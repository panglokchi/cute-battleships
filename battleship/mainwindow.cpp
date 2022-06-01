#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsView>
#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , opponent((AIPlayer(&player)))
{
    ui->setupUi(this);

    //ui->playerStats->setVisible(false);
    //ui->opponentStats->setVisible(false);

    ui->playerGrid->setScene(&player_scene);
    ui->opponentGrid->setScene(&opponent_scene);

    ui->playerGrid->show();
    ui->opponentGrid->show();


    connect(ui->playerGrid , &PlayerGrid::mouseClicked, this, &MainWindow::player_grid_clicked);
    connect(ui->playerGrid , &PlayerGrid::mouseHover, this, &MainWindow::player_grid_hover);
    connect(ui->playerGrid , &PlayerGrid::mouseRightClicked, this, &MainWindow::player_grid_right_clicked);

    connect(ui->opponentGrid , &PlayerGrid::mouseClicked, this, &MainWindow::opponent_grid_clicked);

    connect(ui->playerShipCV , SIGNAL(released()) , this , SLOT( handlePlayerShipCV() ) );
    connect(ui->playerShipBB , SIGNAL(released()) , this , SLOT( handlePlayerShipBB() ) );
    connect(ui->playerShipCA , SIGNAL(released()) , this , SLOT( handlePlayerShipCA() ) );
    connect(ui->playerShipSS , SIGNAL(released()) , this , SLOT( handlePlayerShipSS() ) );
    connect(ui->playerShipDD , SIGNAL(released()) , this , SLOT( handlePlayerShipDD() ) );
    connect(ui->randomDeploy , SIGNAL(released()) , this , SLOT( random_deploy() ) );
    connect(ui->resetShips , SIGNAL(released()) , this , SLOT( reset_ships() ) );
    connect(ui->begin , SIGNAL(released()) , this , SLOT( begin() ) );

    //set_player_scene_background();
    //set_opponent_scene_background();
    set_scene_background(player_scene);
    set_scene_background(opponent_scene);

    QPushButton* player_ship_icons[5] = { ui->playerShipCV , ui->playerShipBB , ui->playerShipCA , ui->playerShipSS , ui->opponentShipDD };
    player.linkShipIcons( player_ship_icons );

    QPushButton* opponent_ship_icons[5] = { ui->opponentShipCV , ui->opponentShipBB , ui->opponentShipCA , ui->opponentShipSS , ui->opponentShipDD };
    opponent.linkShipIcons( opponent_ship_icons );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::player_grid_clicked(int row, int col) {
    //qDebug()<<row<<col;
    if ( !deployment_phase ) {
        return;
    }

    if ( !player.addShip( selected_ship , row , col , selected_ship_orientation , player_scene) ) {
        return;
    } else if ( player.allDeployed() ) {
        ui->begin->setVisible(true);
    }
    /*
    if ( player.allDeployed() ) {

        qDebug() << "all deployed";
        deployment_phase =  false;
        battle_phase = true;
        opponent.randomDeploy(opponent_scene);

    }*/
}

void MainWindow::opponent_grid_clicked(int row , int col) {
    if ( !battle_phase || game_over ) {
        return;
    }
    qDebug() << "player turn";
    if ( opponent.getGrid().isHit( row , col ) ) {
        return;
    }
    opponent.hit( row , col , opponent_scene );
    qDebug() << "hit opponent"<<row<<col;

    if ( !opponent.hasShipsLeft() ) {
        qDebug() << "Victory";
        QMessageBox msgBox( QMessageBox::Icon::Information , QString::fromStdString("Game Over") , QString::fromStdString("Victory!") );
        msgBox.addButton( QString::fromStdString("OK") , QMessageBox::AcceptRole );
        msgBox.exec();
        game_over = true;
        return;
    }

    is_human_turn = false;
    opponent.aiHit( player_scene );
    qDebug() << "hit player"<<row<<col;
    is_human_turn = true;

    if ( !player.hasShipsLeft() ) {
        qDebug() << "Defeat";
        QMessageBox msgBox( QMessageBox::Icon::Information , QString::fromStdString("Game Over") , QString::fromStdString("Defeat!") );
        msgBox.addButton( QString::fromStdString("OK") , QMessageBox::AcceptRole );
        msgBox.exec();
        game_over = true;
    }

}

void MainWindow::create_position_indicators( Ship::ShipType ship_type, int row, int col, Ship::Orientation orientation) {
    if ( battle_phase ) {
        return;
    }
    if ( row < 0 || row > 9 || col < 0 || col > 9 ) {
        return;
    }
    //int ship_length = int(ship_type);
    int ship_length;
    switch (ship_type) {
        case Ship::ShipType::CV : ship_length = 5 ; break;
        case Ship::ShipType::BB : ship_length = 4 ; break;
        case Ship::ShipType::CA : ship_length = 3 ; break;
        case Ship::ShipType::SS : ship_length = 3 ; break;
        case Ship::ShipType::DD : ship_length = 2 ; break;
    }
    int rotation = 90*int(selected_ship_orientation);
    qDebug() << "rotation" << rotation;
    int row_delta = 0;
    int col_delta = 0;
    switch (int(orientation)) {
        case 0 : row_delta = -1 ; break;
        case 1 : col_delta = 1  ; break;
        case 2 : row_delta = 1  ; break;
        case 3 : col_delta = -1 ; break;
    }
    QGraphicsPixmapItem * ship_stern = player_scene.addPixmap(QPixmap( ":/images/ship_images/ship_stern_green.png" ));

    ship_stern->setOffset(col*16,row*16);
    ship_stern->setTransformOriginPoint(col*16+8,row*16+8);
    ship_stern->setRotation(rotation);
    deployment_phase_position_indicators.append( ship_stern );
    qDebug() << "stern";


    int i = 1;
    for ( ; i < ship_length - 1 ; i++ ) {
        if ( ( col + col_delta * i ) < 0 || ( row + row_delta * i) < 0 || ( col + col_delta * i ) > 9 || ( row + row_delta * i) > 9 ) {
            return;
        }
        QGraphicsPixmapItem * ship_mid = player_scene.addPixmap(QPixmap( ":/images/ship_images/ship_mid_green.png" ));

        ship_mid->setOffset( ( col + col_delta * i ) *16, ( row + row_delta * i) *16);
        ship_mid->setTransformOriginPoint( ( col + col_delta * i ) * 16 + 8 , ( row + row_delta * i) * 16 + 8 );
        ship_mid->setRotation(rotation);
        deployment_phase_position_indicators.append( ship_mid );
        qDebug() << "mid";
    }

    if ( ( col + col_delta * i ) < 0 || ( row + row_delta * i) < 0 || ( col + col_delta * i ) > 9 || ( row + row_delta * i) > 9 ) {
        return;
    }
    QGraphicsPixmapItem * ship_bow = player_scene.addPixmap(QPixmap( ":/images/ship_images/ship_bow_green.png" ));

    ship_bow->setOffset( ( col + col_delta * i ) *16, ( row + row_delta * i) *16);
    ship_bow->setTransformOriginPoint( ( col + col_delta * i ) * 16 + 8 , ( row + row_delta * i) * 16 + 8 );
    ship_bow->setRotation(rotation);
    deployment_phase_position_indicators.append( ship_bow );
    qDebug() << "bow";

}

void MainWindow::player_grid_hover(int row, int col) {
    qDebug()<<row<<col;

    for ( QList<QGraphicsPixmapItem*>::iterator it = deployment_phase_position_indicators.begin() ; it != deployment_phase_position_indicators.end() ; it++ ) {\
         player_scene.removeItem( *it );
    }
    deployment_phase_position_indicators.clear();
    create_position_indicators( selected_ship , row , col , selected_ship_orientation );
    /*
    switch ( selected_ship ) {
        case Ship::ShipType::CV : {
            int rotation = 90*int(selected_ship_orientation);

        }

    }*/
}

void MainWindow::player_grid_right_clicked() {
    qDebug()<<"RIGHTCLICK";
    selected_ship_orientation = Ship::Orientation( ( selected_ship_orientation + 1 ) % 4 );
    qDebug()<<int(selected_ship_orientation)<<"orientation";
}

void MainWindow::set_scene_background(QGraphicsScene& scene) {
    for ( int i = 0 ; i < 10 ; i = i+1 ) {
        for ( int j = 0 ; j < 10 ; j = j+1 ) {
            QGraphicsPixmapItem * map_graphic = scene.addPixmap(QPixmap(":/images/ship_images/empty.png").scaled(16,16));
            scene_map_graphics.append(map_graphic);

            QGraphicsRectItem * map_square = scene.addRect( QRect(j*16,i*16,16,16));
            scene_squares.append(map_square);

            map_graphic->setOffset(16*j,16*i);
            map_graphic->setZValue(-1);

            map_square->setZValue(1);
        }
    }
    qDebug()<<scene.sceneRect();
    /*
    QGraphicsRectItem * scene_rect = scene.addRect( QRect(0,0,160,160) );
    QRectF bounds = scene.itemsBoundingRect();

    scene.setSceneRect( scene_rect->rect() );
    ui->playerGrid->fitInView( scene_rect , Qt::KeepAspectRatio );
    */
    //ui->playerGrid->centerOn(QPointF(0,0));
}
/*
void MainWindow::set_player_scene_background() {
    for ( int i = 0 ; i < 10 ; i = i+1 ) {
        for ( int j = 0 ; j < 10 ; j = j+1 ) {
            QGraphicsPixmapItem * map_graphic = player_scene.addPixmap(QPixmap(":/images/ship_images/empty.png").scaled(16,16));
            player_scene_map_graphics.append(map_graphic);

            QGraphicsRectItem * map_square = player_scene.addRect( QRect(j*16,i*16,16,16));
            player_scene_squares.append(map_square);

            map_graphic->setOffset(16*j,16*i);
            map_graphic->setZValue(-1);

            map_square->setZValue(1);
        }
    }
    qDebug()<<player_scene.sceneRect();
    QGraphicsRectItem * player_scene_rect = player_scene.addRect( QRect(0,0,160,160) );
    QRectF bounds = player_scene.itemsBoundingRect();

    player_scene.setSceneRect( player_scene_rect->rect() );
    ui->playerGrid->fitInView( player_scene_rect , Qt::KeepAspectRatio );
    //ui->playerGrid->centerOn(QPointF(0,0));
}
*/
void MainWindow::showEvent(QShowEvent * show_event) {
    //ui->playerGrid->fitInView(player_scene.sceneRect(),Qt::KeepAspectRatio);
    //ui->opponentGrid->fitInView(opponent_scene.sceneRect(), Qt::KeepAspectRatio);
    ui->playerGrid->fitInView(player_scene.addRect(QRect(0,0,160,160)),Qt::KeepAspectRatio);
    ui->opponentGrid->fitInView(opponent_scene.addRect(QRect(0,0,160,160)), Qt::KeepAspectRatio);
}

void MainWindow::set_opponent_scene_background() {

}

void MainWindow::handlePlayerShipCV() {
    if ( !deployment_phase ) {
        return;
    }
    selected_ship = Ship::ShipType::CV;
}

void MainWindow::handlePlayerShipBB() {
    if ( !deployment_phase ) {
        return;
    }
    selected_ship = Ship::ShipType::BB;
    qDebug() << "BB selected";
}

void MainWindow::handlePlayerShipCA() {
    if ( !deployment_phase ) {
        return;
    }
    selected_ship = Ship::ShipType::CA;
}

void MainWindow::handlePlayerShipSS() {
    if ( !deployment_phase ) {
        return;
    }
    selected_ship = Ship::ShipType::SS;
}

void MainWindow::handlePlayerShipDD() {
    if ( !deployment_phase ) {
        return;
    }
    selected_ship = Ship::ShipType::DD;

}

void MainWindow::random_deploy() {
    player.randomDeploy(player_scene);
    ui->begin->setVisible(true);
}

void MainWindow::reset_ships() {
    player.resetShips();
    ui->begin->setVisible(false);
}

void MainWindow::begin() {
    if ( player.allDeployed() ) {
        qDebug() << "begin";
        deployment_phase =  false;
        battle_phase = true;
        opponent.randomDeploy(opponent_scene);
        ui->randomDeploy->setVisible(false);
        ui->resetShips->setVisible(false);
        ui->begin->setVisible(false);
    }
}
