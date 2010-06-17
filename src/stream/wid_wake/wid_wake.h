/*
* WiderWake
* (C) 1999-2008 Jack Lloyd
*
* Distributed under the terms of the Botan license
*/

#ifndef BOTAN_WIDER_WAKE_H__
#define BOTAN_WIDER_WAKE_H__

#include <botan/stream_cipher.h>

namespace Botan {

/**
* WiderWake4+1-BE
*
* Note: quite old and possibly not safe; use XSalsa20 or a block
* cipher in counter mode.
*/
class BOTAN_DLL WiderWake_41_BE : public StreamCipher
   {
   public:
      void cipher(const byte[], byte[], u32bit);
      void set_iv(const byte[], u32bit);

      bool valid_iv_length(u32bit iv_len) const
         { return (iv_len == 8); }

      void clear();
      std::string name() const { return "WiderWake4+1-BE"; }
      StreamCipher* clone() const { return new WiderWake_41_BE; }
      WiderWake_41_BE() : StreamCipher(16, 16, 1) {}
   private:
      void key_schedule(const byte[], u32bit);

      void generate(u32bit);

      SecureVector<byte, DEFAULT_BUFFERSIZE> buffer;
      SecureVector<u32bit, 256> T;
      SecureVector<u32bit, 5> state;
      SecureVector<u32bit, 4> t_key;
      u32bit position;
   };

}

#endif
