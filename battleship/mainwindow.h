#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "grid.h"
#include "ship.h"
#include "humanplayer.h"
#include "aiplayer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void showEvent(QShowEvent*);

private slots:
    void player_grid_clicked(int row, int col);
    void opponent_grid_clicked(int row, int col);
    void player_grid_hover(int row, int col);
    void player_grid_right_clicked();

    void create_position_indicators( Ship::ShipType ship_type, int row, int cow, Ship::Orientation orientation);

    void handlePlayerShipCV();
    void handlePlayerShipBB();
    void handlePlayerShipCA();
    void handlePlayerShipSS();
    void handlePlayerShipDD();

    void random_deploy();
    void reset_ships();
    void begin();

private:
    HumanPlayer player;
    AIPlayer opponent;

    QGraphicsScene player_scene;
    QGraphicsScene opponent_scene;

    //QList<QGraphicsPixmapItem*> player_scene_map_graphics;
    //QList<QGraphicsRectItem*> player_scene_squares;
    QList<QGraphicsPixmapItem*> scene_map_graphics;
    QList<QGraphicsRectItem*> scene_squares;

    QList<QGraphicsPixmapItem*> player_ship_graphics;

    QList<QGraphicsPixmapItem*> deployment_phase_position_indicators;

    Ui::MainWindow *ui;

    bool deployment_phase{true};
    bool battle_phase{false};
    bool is_human_turn{true};
    bool game_over{false};
    Ship::ShipType selected_ship{ Ship::ShipType::CV };
    Ship::Orientation selected_ship_orientation{ Ship::Orientation::N };

    void set_player_scene_background();
    void set_opponent_scene_background();

    void set_scene_background(QGraphicsScene& scene);

};
#endif // MAINWINDOW_H
