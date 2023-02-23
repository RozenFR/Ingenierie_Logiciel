//
// Created by iamze on 23/02/2023.
//

#ifndef CLIENTCPP_COORDINATESCONVERTER_HPP
#define CLIENTCPP_COORDINATESCONVERTER_HPP

#include <utility>

class CoordinatesConverter {

private:
    double worldX;
    double worldY;
    double scaleX;
    double scaleY;

public:
    /**
     * Constructeur de CoordinatesConverter.
     * Calcule les valeurs pour convertir les coordonnées du monde en coordonnées d'écran.
     *
     * @param screenWidth La largeur de l'écran en pixels.
     * @param screenHeight La hauteur de l'écran en pixels.
     * @param worldWidth La largeur de l'espace de travail en unités du monde.
     * @param worldHeight La hauteur de l'espace de travail en unités du monde.
     * @param worldX La position horizontale de l'origine de l'espace de travail en unités du monde.
     * @param worldY La position verticale de l'origine de l'espace de travail en unités du monde.
     */
    CoordinatesConverter(double screenWidth, double screenHeight,
                         double worldWidth, double worldHeight,
                         double worldX, double worldY) {
        // Stockage des valeurs de l'espace de travail.
        this->worldX = worldX;
        this->worldY = worldY;

        // Calcul des facteurs d'échelle pour chaque axe.
        this->scaleX = screenWidth / worldWidth;
        this->scaleY = screenHeight / worldHeight;
    }

    /**
     * Convertit les coordonnées du monde en coordonnées d'écran.
     *
     * @param worldX La position horizontale en unités du monde.
     * @param worldY La position verticale en unités du monde.
     * @return Les coordonnées d'écran correspondantes.
     */
    std::pair<double, double> worldToScreen(double worldX, double worldY) {
        // Calcul de la position en pixels à partir des coordonnées du monde.
        double screenX = (worldX - this->worldX) * this->scaleX;
        double screenY = (worldY - this->worldY) * this->scaleY;

        return std::make_pair(screenX, screenY);
    }

    /**
     * Convertit les coordonnées d'écran en coordonnées du monde.
     *
     * @param screenX La position horizontale en pixels.
     * @param screenY La position verticale en pixels.
     * @return Les coordonnées du monde correspondantes.
     */
    std::pair<double, double> screenToWorld(double screenX, double screenY) {
        // Calcul de la position en unités du monde à partir des coordonnées d'écran.
        double worldX = screenX / this->scaleX + this->worldX;
        double worldY = screenY / this->scaleY + this->worldY;

        return std::make_pair(worldX, worldY);
    }
};


#endif //CLIENTCPP_COORDINATESCONVERTER_HPP
