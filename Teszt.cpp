#include "fuggvenyek.h"

int main()
{
    string fuggveny;//ide várom a kiértékelendő függvényt
    int hossz;
    bool olvass= true;

    while(olvass)
    {
        /**
     * Kiírja a felhasználó feladatát, és beolvassa a bemeneten érkezett függvényt, valamint leszámolja annak a hosszát
     */
        hossz=fuggvenykeres(fuggveny);

        /**
         * Kikeresi a hibákat amik felmerülhetek a függvény megadásakor
         */
        olvass=hibakereses(fuggveny, hossz);
    }
    /**
 * Kikeresi a változókat és azoknak az értékeit is bekéri
 */
    valtozo_kereses(hossz, fuggveny);
    /**
     * Kiértékelése a függvénynek
     */
    kiertekeles(fuggveny, hossz);
    fuggveny.erase(0, 1);
    return 0;
}