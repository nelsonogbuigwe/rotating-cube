//
// Created by Chineben Nelson Ogbuigwe on 8/24/23.
//
#include <iostream>
#include <cmath>
#include <thread>
#include <chrono>

const int cubeSize = 5;

struct Vector3 {
    double x, y, z;
};

Vector3 rotatePoint(Vector3 point, double angleX, double angleY, double angleZ) {
    Vector3 rotatedPoint;
    rotatedPoint.x = point.x * cos(angleY) - point.z * sin(angleY);
    rotatedPoint.z = point.x * sin(angleY) + point.z * cos(angleY);
    rotatedPoint.y = point.y * cos(angleX) - rotatedPoint.z * sin(angleX);
    rotatedPoint.z = point.y * sin(angleX) + rotatedPoint.z * cos(angleX);
    double tempX = rotatedPoint.x;
    rotatedPoint.x = tempX * cos(angleZ) - rotatedPoint.y * sin(angleZ);
    rotatedPoint.y = tempX * sin(angleZ) + rotatedPoint.y * cos(angleZ);
    return rotatedPoint;
}

void clearScreen() {
    // Clear the console screen
    std::cout << "\x1B[2J\x1B[H";
}

void drawCube(Vector3 vertices[]) {
    // Connect vertices to create cube edges
    for (int i = 0; i < 4; ++i) {
        std::cout << "  " << vertices[i].x << "," << vertices[i].y << "," << vertices[i].z << "  ";
        if (i < 3) std::cout << "   ";
    }
    std::cout << std::endl;
    std::cout << "      |     |     |     |" << std::endl;
    std::cout << "      +-----+-----+-----+" << std::endl;
    for (int i = 4; i < 8; ++i) {
        std::cout << "  " << vertices[i].x << "," << vertices[i].y << "," << vertices[i].z << "  ";
        if (i < 7) std::cout << "   ";
    }
    std::cout << std::endl;
    std::cout << "      |     |     |     |" << std::endl;
    std::cout << "      +-----+-----+-----+" << std::endl;
    for (int i = 0; i < 4; ++i) {
        std::cout << "  " << vertices[i].x << "," << vertices[i].y << "," << vertices[i].z << "  ";
        if (i < 3) std::cout << "   ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

int main() {
    Vector3 vertices[8] = {
            {-cubeSize, -cubeSize, -cubeSize}, {cubeSize, -cubeSize, -cubeSize},
            {cubeSize, cubeSize, -cubeSize}, {-cubeSize, cubeSize, -cubeSize},
            {-cubeSize, -cubeSize, cubeSize}, {cubeSize, -cubeSize, cubeSize},
            {cubeSize, cubeSize, cubeSize}, {-cubeSize, cubeSize, cubeSize}
    };

    double angleX = 0.0;
    double angleY = 0.0;
    double angleZ = 0.0;

    while (true) {
        clearScreen();
        Vector3 rotatedVertices[8];

        for (int i = 0; i < 8; ++i) {
            rotatedVertices[i] = rotatePoint(vertices[i], angleX, angleY, angleZ);
        }

        drawCube(rotatedVertices);

        angleX += 0.05;
        angleY += 0.05;
        angleZ += 0.03;

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}
