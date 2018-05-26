# LDE-AutomaS10
Experimento de Sistema de Automação de equipamentos do Laboratório de Embarcados - S10 do Labotec 3


## ESP8266
Código usando IDE do Arduino.
Depende da instalação da biblioteca de placas ESP8266, etc.
Para tanto, a IDE precisa ser da versão igual ou mais recente que 1.8.5.
1. Em preferência, adicionar a url adicional de gerenciamento de placas:
```
http://arduino.esp8266.com/stable/package_esp8266com_index.json
```
2. Em seguida, buscar e instalar o pacote esp8266 no **Gerenciador de Placas** em **ferramentas->placa->Gerenciador de Placas**
3. Após instalação do pacote, selecionar a placa correspondente, neste projeto usamos NodeMCU 1.0 (ESP12-E Module).

O processo de gravação segue de forma padrão a partir daí.

## Page
Prototipo da página servida pelo NodeMCU, o código contido nessa pagina deve ser convertido em uma String e copiado para o código do ESP.
Esses arquivos servem para experimentar a página e fazer as devidas modificações antes que esta seja impantada no NodeMCU.
