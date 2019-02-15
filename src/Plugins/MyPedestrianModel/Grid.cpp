//
// Created by florenciaprado on 12/02/19.
//

#include "Grid.h"
#include "Cell.h"


using namespace std;

#pragma region BASE

namespace MyModel {
    Grid::Grid() {
        grid_width = grid_height = 0;
    }

    Grid::Grid(int width, int height) {
        grid_width = width;
        grid_height = height;
    }

    bool Grid::checkExists(glm::vec2 cell_pos) {
        int x = cell_pos.x;
        int y = cell_pos.y;

        if (x < 0)
            return false;
        if (x >= grid_width)
            return false;

        if (y < 0)
            return false;
        if (y >= grid_height)
            return false;
        cout << "Cell with the given position found: " << cell_pos.x << "," << cell_pos.y << "\n";

        return true;
    }

    void Grid::getNeighbours(glm::vec2 cell, glm::vec2 *cells) {
        int x = cell.x;
        int y = cell.y;

        cells[0] = glm::vec2(x + 1, y);
        cells[1] = glm::vec2(x, y + 1);
        cells[2] = glm::vec2(x - 1, y);
        cells[3] = glm::vec2(x, y - 1);
    }

    glm::vec2 Grid::findClosestCellPos(glm::vec2 cell_pos) {
        std::vector<glm::vec2> cells_pos(4);

        cells_pos[0] = glm::vec2(glm::floor(cell_pos.x), glm::ceil(cell_pos.y));
        cells_pos[1] = glm::vec2(glm::ceil(cell_pos.x), glm::ceil(cell_pos.y));
        cells_pos[2] = glm::vec2(glm::ceil(cell_pos.x), glm::floor(cell_pos.y));
        cells_pos[3] = glm::vec2(glm::floor(cell_pos.x), glm::floor(cell_pos.y));

        float min_dist = 999;
        float dist;
        glm::vec2 min_cell_pos(-5.0f);

        for (int i = 1; i < 4; i++) {
            if (checkExists(cells_pos[i])) {
                dist = glm::distance(cells_pos[i], cell_pos);
                if (dist < min_dist)
                    min_cell_pos = cells_pos[i];
            }
        }


        return min_cell_pos;
    }

    SharedGrid::SharedGrid() : Grid() {
        max_slope = min_slope = 0.0f;
    }

    SharedGrid::SharedGrid(int width, int height) : Grid(width, height) {
        min_slope = 0.0f;
        max_slope = 0.0f;
    }

    void SharedGrid::setupGridCells() {
        cell_matrix.resize(grid_width);
        for (int i = 0; i < grid_width; i++) {
            cell_matrix[i].resize(grid_height);
            for (int j = 0; j < grid_height; j++) {
                cell_matrix[i][j].cell_position = glm::vec2(i, j);
                cell_matrix[i][j].grid_size = glm::vec2(grid_width, grid_height);
            }
        }


    }

    SharedCell &SharedGrid::findCellByPos(glm::vec2 pos) {
        return cell_matrix[pos.x][pos.y];
    }
}
