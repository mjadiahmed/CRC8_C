byte CRC_Byte = calculateCRC8(receivedPayload, receivedPayloadSize ); 



byte calculateCRC8(const byte *data, byte dataSize)
{
  if (data == nullptr)
  {
    // handle null input
    return 0;
  }

  const byte POLYNOM_VALUE = 0x07;
  byte crc = 0;

  for (byte i = 0; i < dataSize; i++)
  {
    crc ^= data[i];
    for (byte j = 0; j < 8; j++)
    {
      if (crc & 0x80)
      {
        crc = (crc << 1) ^ POLYNOM_VALUE;
      }
      else
      {
        crc <<= 1;
      }
    }
  }

  return crc;
}
