/*!
   \file acFuncs.h
   \brief Biblioteca de funcções para controlar o ar condicionado

   Biblioteca contendo funções de envio de sinal para o ar condicionado no
   Laboratório de Hardware no Labotec 3 da UEFS.\n
   Os sinais são de funções principais escohidas parafornecer suporte básico
   de controle.
   \author jaca
   \date 14/07/2018
*/

#include <IRLibSendBase.h>    //We need the base code
#include <IRLib_HashRaw.h>    //Only use raw sender

/*! \brief Tamanho do Array de Intervalos*/
#define RAW_DATA_LEN 100
/*! \brief Modulação do sinal em kHz */
#define MODULATION_FREQ 39
/*! \brief Intervalo entre envio de sinal (necessário para esse protocolo) em µs */
#define DELAY_INTERSIG 4700

/*! \brief Sinal de desliga simples */
const uint16_t desligaSig[RAW_DATA_LEN]{
  4538, 4377, 638,  1533, 638,  466,  638,  1520, 638,  1529,
  638,  458,  638,  456,  638,  1529, 638,  461,  638,  453,
  638,  1530, 638,  461,  638,  461,  638,  1538, 638,  1523,
  638,  459,  638,  1530, 638,  463,  638,  1523, 638,  1520,
  638,  1522, 638,  1522, 638,  458,  638,  1530, 638,  1519,
  638,  1531, 638,  453,  638,  458,  638,  466,  638,  461,
  638,  1520, 638,  461,  638,  459,  638,  1532, 638,  1519,
  638,  1523, 638,  450,  638,  466,  638,  466,  638,  453,
  638,  458,  638,  466,  638,  458,  638,  461,  638,  1522,
  638,  1520, 638,  1519, 638,  1538, 638,  1517, 638,  1000
};

/*! \brief Sinal de liga em 21 graus */
const uint16_t liga21Sig[RAW_DATA_LEN]{
  4550, 4376, 638,  1543, 638,  466,  638,  1521, 638,  1523,
  638,  466,  638,  450,  638,  1523, 638,  466,  638,  450,
  638,  1538, 638,  456,  638,  457,  638,  1520, 638,  1516,
  638,  466,  638,  1538, 638,  1528, 638,  450,  638,  1538,
  638,  1522, 638,  1523, 638,  1524, 638,  1520, 638,  1516,
  638,  466,  638,  1538, 638,  450,  638,  466,  638,  466,
  638,  498,  638,  466,  638,  466,  638,  470,  638,  1524,
  638,  1520, 638,  466,  638,  456,  638,  456,  638,  450,
  638,  466,  638,  1524, 638,  453,  638,  466,  638,  1521,
  638,  1523, 638,  1524, 638,  1520, 638,  1524, 638,  1000
};

/*! \brief Sinal de temperatura 18 graus */
const uint16_t temp18[RAW_DATA_LEN]{
  4550, 4379, 638,  1525, 638,  466,  638,  1524, 638,  1520,
  638,  466,  638,  450,  638,  1538, 638,  466,  638,  450,
  638,  1523, 638,  466,  638,  457,  638,  1524, 638,  1520,
  638,  466,  638,  1522, 638,  1543, 638,  456,  638,  1538,
  638,  1520, 638,  1521, 638,  1523, 638,  1538, 638,  1519,
  638,  466,  638,  1521, 638,  456,  638,  466,  638,  450,
  638,  456,  638,  466,  638,  453,  638,  474,  638,  492,
  638,  450,  638,  1523, 638,  466,  638,  466,  638,  453,
  638,  457,  638,  1538, 638,  1520, 638,  1524, 638,  450,
  638,  1538, 638,  1542, 638,  1522, 638,  1538, 638,  1000
};

/*! \brief Sinal de temperatura 21 graus */
const uint16_t temp21[RAW_DATA_LEN]{
  4550, 4378, 638,  1532, 638,  456,  638,  1525, 638,  1538,
  638,  466,  638,  466,  638,  1523, 638,  457,  638,  469,
  638,  1525, 638,  457,  638,  453,  638,  1522, 638,  1538,
  638,  466,  638,  1538, 638,  1528, 638,  469,  638,  1525,
  638,  1525, 638,  1538, 638,  1538, 638,  1523, 638,  1519,
  638,  457,  638,  1532, 638,  457,  638,  453,  638,  456,
  638,  457,  638,  456,  638,  453,  638,  469,  638,  1538,
  638,  1522, 638,  469,  638,  456,  638,  456,  638,  469,
  638,  456,  638,  1522, 638,  456,  638,  456,  638,  1525,
  638,  1538, 638,  1523, 638,  1522, 638,  1522, 638,  1000
};

/*! \brief Sinal de temperatura 25 graus */
const uint16_t temp25[RAW_DATA_LEN]{
  4550, 4380, 638,  1528, 638,  466,  638,  1522, 638,  1523,
  638,  466,  638,  450,  638,  1523, 638,  466,  638,  450,
  638,  1538, 638,  450,  638,  466,  638,  1525, 638,  1522,
  638,  466,  638,  1519, 638,  1541, 638,  466,  638,  1525,
  638,  1519, 638,  1516, 638,  1538, 638,  1522, 638,  1522,
  638,  466,  638,  1519, 638,  466,  638,  466,  638,  450,
  638,  456,  638,  457,  638,  466,  638,  1538, 638,  1541,
  638,  466,  638,  466,  638,  453,  638,  457,  638,  466,
  638,  466,  638,  466,  638,  450,  638,  1522, 638,  1522,
  638,  1538, 638,  1519, 638,  1538, 638,  1522, 638,  1000
};

/*!
   \brief Função de emissão de sinal padrão.

   Emite o sinal passado em sigArray[] usando o sender e as constantes padrão de
   tamanho do sinal e frequencia de modulação.
   \param IRsendRaw * sender - Objeto de envio de sinal da biblioteca IRlib2
   \param uint16_t sigArray[] - Array de intercvalos do Sinal
   \param char * msg - Mensagem de saída Serial
   \pre -
   \post -
   \return void
*/
void acCommand(IRsendRaw * sender, uint16_t sigArray[], char * msg){
  (*sender).send(sigArray, RAW_DATA_LEN, MODULATION_FREQ);
  delayMicroseconds(DELAY_INTERSIG);
  (*sender).send(sigArray, RAW_DATA_LEN, MODULATION_FREQ);
  Serial.print("[ OK ] AC: ");
  Serial.println(msg);
};

/*!
   \brief Envia o sinal de ligar ar-condicionado

   Envia o sinal de ligar o ar-condicionado em 21 graus e no modo Cool.\n
   O sinal foi capturado diretamente do controle remoto do aparelho no modo Cool,
   ṕara resfriamento e em 21 graus de tempereatura, sem swing das paletas.
   \param IRsendRaw sender - Objeto de envio de sinal cru para o pino 3, invariavelmente
   \pre -
   \post -
   \return void
*/
void acLiga(IRsendRaw sender){
  acCommand(&sender, liga21Sig, "liga 21 g");
};

/*!
   \brief Envia o sinal de temperatura Máxima, escolhido 25 graus C

   Envia o sinal de temperatura de 25 graus para o aparelho de ar-condicionado.\n
   Independe de modo.
   \param IRsendRaw sender - Objeto de envio de sinal cru para o pino 3, invariavelmente
   \pre -
   \post -
   \return void
*/
void acTempMax(IRsendRaw sender){
  acCommand(&sender, temp25, "temperatura:25g");
};

/*!
   \brief Envia o sinal de temperatura Minima, escolhido 18 graus C

   Envia o sinal de temperatura de 18 graus para o aparelho de ar-condicionado.\n
   Independe de modo.
   \param IRsendRaw sender - Objeto de envio de sinal cru para o pino 3, invariavelmente
   \pre -
   \post -
   \return void
*/
void acTempMin(IRsendRaw sender){
  acCommand(&sender, temp18, "temperatura:18g");
};

/*!
   \brief Envia o sinal de temperatura Média, escolhido 21 graus C

   Envia o sinal de temperatura de 21 graus para o aparelho de ar-condicionado.\n
   Independe de modo
   \param IRsendRaw sender - Objeto de envio de sinal cru para o pino 3, invariavelmente
   \pre -
   \post -
   \return void
*/
void acTempMid(IRsendRaw sender){
  acCommand(&sender, temp21, "temperatura:21g");
};


/*!
   \brief Envia o sinal de desligar ar-condicionado

   Usa o objeto sender para enviar um sinal de desligar o ar-condicionado.\n
   O sinal foi capturado diretamente do controle remoto do ar-condicionado instalado.\n
   Não é possivel configurar esse sinal.\n
   \param IRsendRaw sender - Objeto de envio de sinal cru para o pino 3, invariavelmente
   \pre -
   \post -
   \return void
*/
void acDesliga(IRsendRaw sender){
  acCommand(&sender, desligaSig, "desliga");
};
