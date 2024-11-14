// trabajo practico integrador.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <SFML/Graphics.hpp>
#include <stdexcept>
#include <cstdlib>  // Para usar rand() y srand()
#include <ctime>    // Para usar time() y asegurar que los números aleatorios cambien

class Enemigo {
public:
    Enemigo(const std::string& texturaArchivo, float y, float velocidad)
        : velocidad(velocidad) {
        if (!textura.loadFromFile(texturaArchivo)) {
            throw std::runtime_error("No se pudo cargar la textura del enemigo");
        }
        sprite.setTexture(textura);
        sprite.setPosition(rand() % 800, y);
        sprite.setScale(0.1f, 0.1f);  // Ajusta el tamaño del enemigo
        moverDerecha = rand() % 2 == 0;
    }

    // Mueve al enemigo
    void mover(float deltaTime) {
        if (moverDerecha) {
            sprite.move(velocidad * deltaTime, 0);
            if (sprite.getPosition().x > 800) {
                sprite.setPosition(0, sprite.getPosition().y);
            }
        }
        else {
            sprite.move(-velocidad * deltaTime, 0);
            if (sprite.getPosition().x < 0) {
                sprite.setPosition(800, sprite.getPosition().y);
            }
        }
    }

    // Dibuja al enemigo en la ventana
    void dibujar(sf::RenderWindow& ventana) {
        ventana.draw(sprite);
    }

    // Verifica si el enemigo fue clickeado
    bool isClicked(const sf::Vector2i& mousePos) {
        return sprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
    }

    // Elimina al enemigo (lo pone fuera de la pantalla)
    void eliminar() {
        sprite.setPosition(-100, -100);  // Poner al enemigo fuera de la pantalla
    }

    sf::FloatRect getBounds() {
        return sprite.getGlobalBounds();
    }

private:
    sf::Texture textura;
    sf::Sprite sprite;
    float velocidad;
    bool moverDerecha;
};

class Civil {
public:
    Civil(const std::string& texturaArchivo, float y, float velocidad)
        : velocidad(velocidad) {
        if (!textura.loadFromFile(texturaArchivo)) {
            throw std::runtime_error("No se pudo cargar la textura del civil");
        }
        sprite.setTexture(textura);
        sprite.setPosition(rand() % 800, y);  // Posición aleatoria en el eje X y en la mitad inferior en el eje Y
        sprite.setScale(0.1f, 0.1f);  // Ajusta el tamaño del civil
        moverDerecha = rand() % 2 == 0;
    }

    // Mueve al civil
    void mover(float deltaTime) {
        if (moverDerecha) {
            sprite.move(velocidad * deltaTime, 0);
            if (sprite.getPosition().x > 800) {
                sprite.setPosition(0, sprite.getPosition().y);
            }
        }
        else {
            sprite.move(-velocidad * deltaTime, 0);
            if (sprite.getPosition().x < 0) {
                sprite.setPosition(800, sprite.getPosition().y);
            }
        }
    }

    // Dibuja al civil en la ventana
    void dibujar(sf::RenderWindow& ventana) {
        ventana.draw(sprite);
    }

    // Verifica si el civil ha sido clickeado
    bool isClicked(const sf::Vector2i& mousePos) {
        return sprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
    }

    // Elimina al civil (lo pone fuera de la pantalla)
    void eliminar() {
        sprite.setPosition(-100, -100);  // Poner al civil fuera de la pantalla
    }

    sf::FloatRect getBounds() {
        return sprite.getGlobalBounds();
    }

private:
    sf::Texture textura;
    sf::Sprite sprite;
    float velocidad;
    bool moverDerecha;
};

int main() {
    srand(static_cast<unsigned int>(time(0)));

    sf::RenderWindow window(sf::VideoMode(800, 600), "Shooter");

    // Cargar la textura del mapa
    sf::Texture mapTexture;
    if (!mapTexture.loadFromFile("haven4.jpg")) {
        return -1;
    }

    sf::Sprite mapSprite;
    mapSprite.setTexture(mapTexture);

    // Ajustar el tamaño del mapa sin distorsionarlo
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u textureSize = mapTexture.getSize();
    float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
    float scaleY = static_cast<float>(windowSize.y) / textureSize.y;

    // Escalar el mapa para llenar la ventana sin distorsionar su proporción
    mapSprite.setScale(scaleX, scaleY);

    // Crear enemigos
    Enemigo enemigo1("enemigo.png", rand() % (windowSize.y / 2) + (windowSize.y / 2), 150.0f); // Mitad inferior
    Enemigo enemigo2("enemigo.png", rand() % (windowSize.y / 2) + (windowSize.y / 2), 120.0f); // Mitad inferior
    Enemigo enemigo3("enemigo.png", rand() % (windowSize.y / 2) + (windowSize.y / 2), 100.0f); // Mitad inferior
    Enemigo enemigo4("enemigo.png", rand() % (windowSize.y / 2) + (windowSize.y / 2), 150.0f); // Mitad inferior
    Enemigo enemigo5("enemigo.png", rand() % (windowSize.y / 2) + (windowSize.y / 2), 120.0f); // Mitad inferior
    Enemigo enemigo6("enemigo.png", rand() % (windowSize.y / 2) + (windowSize.y / 2), 100.0f); // Mitad inferior
    Enemigo enemigo7("enemigo.png", rand() % (windowSize.y / 2) + (windowSize.y / 2), 150.0f); // Mitad inferior
    Enemigo enemigo8("enemigo.png", rand() % (windowSize.y / 2) + (windowSize.y / 2), 120.0f); // Mitad inferior
    Enemigo enemigo9("enemigo.png", rand() % (windowSize.y / 2) + (windowSize.y / 2), 100.0f); // Mitad inferior
    Enemigo enemigo10("enemigo.png", rand() % (windowSize.y / 2) + (windowSize.y / 2), 150.0f); // Mitad inferior
    Enemigo enemigo11("enemigo.png", rand() % (windowSize.y / 2) + (windowSize.y / 2), 120.0f); // Mitad inferior
    Enemigo enemigo12("enemigo.png", rand() % (windowSize.y / 2) + (windowSize.y / 2), 100.0f); // Mitad inferior
    Enemigo enemigo13("enemigo.png", rand() % (windowSize.y / 2) + (windowSize.y / 2), 150.0f); // Mitad inferior
    Enemigo enemigo14("enemigo.png", rand() % (windowSize.y / 2) + (windowSize.y / 2), 120.0f); // Mitad inferior
    Enemigo enemigo15("enemigo.png", rand() % (windowSize.y / 2) + (windowSize.y / 2), 100.0f); // Mitad inferior
    // (agregar más enemigos si es necesario)

    // Crear civiles
    Civil civil1("civil.png", rand() % (windowSize.y / 2) + (windowSize.y / 2), 100.0f); // Mitad inferior
    Civil civil2("civil.png", rand() % (windowSize.y / 2) + (windowSize.y / 2), 80.0f);  // Mitad inferior
    Civil civil3("civil.png", rand() % (windowSize.y / 2) + (windowSize.y / 2), 90.0f);  // Mitad inferior
    Civil civil4("civil.png", rand() % (windowSize.y / 2) + (windowSize.y / 2), 100.0f); // Mitad inferior
    Civil civil5("civil.png", rand() % (windowSize.y / 2) + (windowSize.y / 2), 80.0f);  // Mitad inferior
    Civil civil6("civil.png", rand() % (windowSize.y / 2) + (windowSize.y / 2), 90.0f);  // Mitad inferior
    Civil civil7("civil.png", rand() % (windowSize.y / 2) + (windowSize.y / 2), 100.0f); // Mitad inferior
    Civil civil8("civil.png", rand() % (windowSize.y / 2) + (windowSize.y / 2), 80.0f);  // Mitad inferior
    Civil civil9("civil.png", rand() % (windowSize.y / 2) + (windowSize.y / 2), 90.0f);  // Mitad inferior
    Civil civil10("civil.png", rand() % (windowSize.y / 2) + (windowSize.y / 2), 100.0f); // Mitad inferior
    Civil civil11("civil.png", rand() % (windowSize.y / 2) + (windowSize.y / 2), 80.0f);  // Mitad inferior
    Civil civil12("civil.png", rand() % (windowSize.y / 2) + (windowSize.y / 2), 90.0f);  // Mitad inferior
    Civil civil13("civil.png", rand() % (windowSize.y / 2) + (windowSize.y / 2), 100.0f); // Mitad inferior
    Civil civil14("civil.png", rand() % (windowSize.y / 2) + (windowSize.y / 2), 80.0f);  // Mitad inferior
    Civil civil15("civil.png", rand() % (windowSize.y / 2) + (windowSize.y / 2), 90.0f);  // Mitad inferior
    // (agregar más civiles si es necesario)

    sf::Font font;
    if (!font.loadFromFile("fonts/OpenSans-Italic-VariableFont_wdth,wght.ttf")) {
        return -1;
    }

    // Inicializar el texto para mostrar el puntaje, enemigos muertos y vidas
    int puntaje = 0;
    int enemigosMuertos = 0;
    int vidas = 3;

    sf::Text puntajeText("Puntaje: 0", font, 40);
    puntajeText.setPosition(10, 0);
    puntajeText.setFillColor(sf::Color::White);

    sf::Text enemigosMuertosText("Enemigos Muertos: 0", font, 20);
    enemigosMuertosText.setPosition(10, 40);
    enemigosMuertosText.setFillColor(sf::Color::White);

    sf::Text vidasText("Vidas: 3", font, 20);
    vidasText.setPosition(10, 70);
    vidasText.setFillColor(sf::Color::White);

    sf::Text startText("Iniciar Juego", font, 30);
    startText.setPosition(300, 200);
    startText.setFillColor(sf::Color::White);

    sf::Text exitText("Salir", font, 30);
    exitText.setPosition(300, 300);
    exitText.setFillColor(sf::Color::White);

    bool isPlaying = false;

    // Cargar la textura de la mira
    sf::Texture crosshairTexture;
    if (!crosshairTexture.loadFromFile("crosshair.png")) {
        return -1;  // Error al cargar la textura de la mira
    }
    sf::Sprite crosshairSprite;
    crosshairSprite.setTexture(crosshairTexture);
    crosshairSprite.setScale(0.15f, 0.15f);  // Aumentamos la escala para hacer la mira más grande

    sf::Clock deltaClock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                if (!isPlaying && startText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    isPlaying = true;
                }
                else if (!isPlaying && exitText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    window.close();
                }

                // Verificar clic en los enemigos
                if (isPlaying) {
                    if (enemigo1.isClicked(mousePos)) {
                        enemigo1.eliminar();
                        puntaje += 10;
                        enemigosMuertos++;
                    }
                    if (enemigo2.isClicked(mousePos)) {
                        enemigo2.eliminar();
                        puntaje += 10;
                        enemigosMuertos++;
                    }
                    if (enemigo3.isClicked(mousePos)) {
                        enemigo3.eliminar();
                        puntaje += 10;
                        enemigosMuertos++;
                    }
                    if (enemigo4.isClicked(mousePos)) {
                        enemigo4.eliminar();
                        puntaje += 10;
                        enemigosMuertos++;
                    }
                    if (enemigo5.isClicked(mousePos)) {
                        enemigo5.eliminar();
                        puntaje += 10;
                        enemigosMuertos++;
                    }
                    if (enemigo6.isClicked(mousePos)) {
                        enemigo6.eliminar();
                        puntaje += 10;
                        enemigosMuertos++;
                    }
                    if (enemigo7.isClicked(mousePos)) {
                        enemigo7.eliminar();
                        puntaje += 10;
                        enemigosMuertos++;
                    }
                    if (enemigo8.isClicked(mousePos)) {
                        enemigo8.eliminar();
                        puntaje += 10;
                        enemigosMuertos++;
                    }
                    if (enemigo9.isClicked(mousePos)) {
                        enemigo9.eliminar();
                        puntaje += 10;
                        enemigosMuertos++;
                    }
                    if (enemigo10.isClicked(mousePos)) {
                        enemigo10.eliminar();
                        puntaje += 10;
                        enemigosMuertos++;
                    }
                    if (enemigo11.isClicked(mousePos)) {
                        enemigo11.eliminar();
                        puntaje += 10;
                        enemigosMuertos++;
                    }
                    if (enemigo12.isClicked(mousePos)) {
                        enemigo12.eliminar();
                        puntaje += 10;
                        enemigosMuertos++;
                    }
                    if (enemigo13.isClicked(mousePos)) {
                        enemigo13.eliminar();
                        puntaje += 10;
                        enemigosMuertos++;
                    }
                    if (enemigo14.isClicked(mousePos)) {
                        enemigo14.eliminar();
                        puntaje += 10;
                        enemigosMuertos++;
                    }
                    if (enemigo15.isClicked(mousePos)) {
                        enemigo15.eliminar();
                        puntaje += 10;
                        enemigosMuertos++;
                    }


                    // Verificar clic en los civiles
                    if (civil1.isClicked(mousePos)) {
                        civil1.eliminar();
                        puntaje += 5; // O la cantidad que desees
                        vidas--;
                    }
                    if (civil2.isClicked(mousePos)) {
                        civil2.eliminar();
                        puntaje += 5;
                        vidas--;
                    }
                    if (civil3.isClicked(mousePos)) {
                        civil3.eliminar();
                        puntaje += 5;
                        vidas--;
                    }
                    if (civil4.isClicked(mousePos)) {
                        civil4.eliminar();
                        puntaje += 5;
                        vidas--;
                    }
                    if (civil5.isClicked(mousePos)) {
                        civil5.eliminar();
                        puntaje += 5;
                        vidas--;
                    }
                    if (civil6.isClicked(mousePos)) {
                        civil6.eliminar();
                        puntaje += 5;
                        vidas--;
                    }
                    if (civil7.isClicked(mousePos)) {
                        civil7.eliminar();
                        puntaje += 5;
                        vidas--;
                    }
                    if (civil8.isClicked(mousePos)) {
                        civil8.eliminar();
                        puntaje += 5;
                        vidas--;
                    }
                    if (civil9.isClicked(mousePos)) {
                        civil9.eliminar();
                        puntaje += 5;
                        vidas--;
                    }
                    if (civil10.isClicked(mousePos)) {
                        civil10.eliminar();
                        puntaje += 5;
                        vidas--;
                    }
                    if (civil11.isClicked(mousePos)) {
                        civil11.eliminar();
                        puntaje += 5;
                        vidas--;
                    }
                    if (civil12.isClicked(mousePos)) {
                        civil12.eliminar();
                        puntaje += 5;
                        vidas--;
                    }
                    if (civil13.isClicked(mousePos)) {
                        civil13.eliminar();
                        puntaje += 5;
                        vidas--;
                    }
                    if (civil14.isClicked(mousePos)) {
                        civil14.eliminar();
                        puntaje += 5;
                        vidas--;
                    }
                    if (civil15.isClicked(mousePos)) {
                        civil15.eliminar();
                        puntaje += 5;
                        vidas--;
                    }

                }
            }
        }

        if (isPlaying) {
            float deltaTime = deltaClock.restart().asSeconds();

            // Mover enemigos y civiles
            enemigo1.mover(deltaTime);
            enemigo2.mover(deltaTime);
            enemigo3.mover(deltaTime);
            enemigo4.mover(deltaTime);
            enemigo5.mover(deltaTime);
            enemigo6.mover(deltaTime);
            enemigo7.mover(deltaTime);
            enemigo8.mover(deltaTime);
            enemigo9.mover(deltaTime);
            enemigo10.mover(deltaTime);
            enemigo11.mover(deltaTime);
            enemigo12.mover(deltaTime);
            enemigo13.mover(deltaTime);
            enemigo14.mover(deltaTime);
            enemigo15.mover(deltaTime);
            civil1.mover(deltaTime);
            civil2.mover(deltaTime);
            civil3.mover(deltaTime);
            civil4.mover(deltaTime);
            civil5.mover(deltaTime);
            civil6.mover(deltaTime);
            civil7.mover(deltaTime);
            civil8.mover(deltaTime);
            civil9.mover(deltaTime);
            civil10.mover(deltaTime);
            civil11.mover(deltaTime);
            civil12.mover(deltaTime);
            civil13.mover(deltaTime);
            civil14.mover(deltaTime);
            civil15.mover(deltaTime);



            // Verificar fin del juego
            if (enemigosMuertos >= 15 || vidas <= 0) {
                isPlaying = false;  // Fin del juego
            }

            // Actualizar los textos
            puntajeText.setString("Puntaje: " + std::to_string(puntaje));
            enemigosMuertosText.setString("Enemigos Muertos: " + std::to_string(enemigosMuertos));
            vidasText.setString("Vidas: " + std::to_string(vidas));
        }

        window.clear();
        window.draw(mapSprite);

        if (isPlaying) {
            enemigo1.dibujar(window);
            enemigo2.dibujar(window);
            enemigo3.dibujar(window);
            enemigo4.dibujar(window);
            enemigo5.dibujar(window);
            enemigo6.dibujar(window);
            enemigo7.dibujar(window);
            enemigo8.dibujar(window);
            enemigo9.dibujar(window);
            enemigo10.dibujar(window);
            enemigo11.dibujar(window);
            enemigo12.dibujar(window);
            enemigo13.dibujar(window);
            enemigo14.dibujar(window);
            enemigo15.dibujar(window);
            civil1.dibujar(window);
            civil2.dibujar(window);
            civil3.dibujar(window);
            civil4.dibujar(window);
            civil5.dibujar(window);
            civil6.dibujar(window);
            civil7.dibujar(window);
            civil8.dibujar(window);
            civil9.dibujar(window);
            civil10.dibujar(window);
            civil11.dibujar(window);
            civil12.dibujar(window);
            civil13.dibujar(window);
            civil14.dibujar(window);
            civil15.dibujar(window);
        }
        else {
            window.draw(startText);
            window.draw(exitText);
        }

        window.draw(puntajeText);
        window.draw(enemigosMuertosText);
        window.draw(vidasText);

        if (isPlaying) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            crosshairSprite.setPosition(static_cast<float>(mousePos.x - crosshairSprite.getGlobalBounds().width / 2),
                static_cast<float>(mousePos.y - crosshairSprite.getGlobalBounds().height / 2));
            window.draw(crosshairSprite);
        }

        window.display();
    }

    return 0;
}


















// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
