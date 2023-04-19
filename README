# PROJEKT GPIO-CONTROL
*------------------*
Projekt řeší přístup GPIO pinům na Raspberry Pi. Cílem bylo vzít si typické projekty s blikající ledkou a nějak to přetvořit a vylepšit. Výstupem je grafická okénková aplikace vytvořená ve frameworku Qt. Aplikace má dva módy: gpio-control a morsecode.

První mód, gpio-control, se spouští jako výchozí a obsahuje 38 tlačítek reprezentující GPIO piny a respektující fyzické rozložení (viz "projekt/gpio_layout.png"). Tlačítka umožňují přístup k libovolným konfigurovatelným GPIO pinům a jejich nastavení jako "OUT". Po stisknutí tlačítka se tedy vyexportuje vybraný GPIO, nastaví se jako OUT a pustí se do něj 3V3 napětí. Po dalším stisknutí tlačítka (ToggleButton) se GPIO odexportuje a přestane se do něj poštět napětí.

Druhý mód, morsecode, je jednoduchou aplikací výše uvedené funkcionality. Uživateli je v ComboBoxu dáno na výběr, ke kterému pinu je připojen (funkcionalitu zapojení lze přímočaře otestovat v módu gpio-control). Do LineEditu pak může zadat text, který chce zakódoat do morseovky. Po stisknutí ENTER se zadaný text vybliká na zapojené LED.

### POZNÁMKY
*------*
*run as root, specify platform xcb.
1. sudo -i
2. cd to directory cont. the binary
3. ./FULLvforraspi -platform xcb

*Pro vývoj kódu bylo potřeba zajstit cross-compilátor pro raspberry pi a nainstalovat všechny potřebné knihovny. Postupoval jsem podle návodu na Qwiki (https://wiki.qt.io/index.php?title=RaspberryPi2EGLFS).
*Bohužel, jsem zatím nedokázal vyřešit deployment pro verzi kódu zkompilovanou cross-compilátorem. Uživatel tedy musí mít nainstalovaný Qt na svém Raspberry Pi.

*Kód byl vyvíjen a testován na Raspberry Pi 3B, Stejné rozložení pinů se ovšem nachází na všech Raspberry Pi novějších než modely 1 a vyjma modelů Zero. Nicméně na jiných modelech kód testován nebyl.

*Použito pro zapojení:
-Raspberry Pi 3B vybaven frameworkem Qt.
-nepájivé pole
-330 Ohm rezistor
-LED
-2 male to female jumpery

*Tlačítek je 38, zatímco pinů 40, vynechány byly piny 27 a 28, které jsou pro pokročilé použití. Navíc jejich vynecháním nebyl nikterak rozhozen widget oproti fyzickému rozložení.

*pro zobrazení aplikace bez přístupu k pinům na 64bit Linux/deb desktopu lze využít verzi FULL_desktop.
