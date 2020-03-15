#if !defined(AFX_AES_H__6BDD3760_BDE8_4C42_85EE_6F7A434B81C4__INCLUDED_)
#define AFX_AES_H__6BDD3760_BDE8_4C42_85EE_6F7A434B81C4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "stdafx.h"

class AES  
{
public:
	AES(unsigned char* key);
	virtual ~AES();
	unsigned char* Cipher(unsigned char* input);     //加密
	unsigned char* InvCipher(unsigned char* input);  //解密
	void* Cipher(void* input, int length=0);
	void* InvCipher(void* input, int length);

private:
	unsigned char Sbox[256];      //S盒
	unsigned char InvSbox[256];   //逆S盒
	unsigned char w[11][4][4];    //扩展密钥

	void KeyExpansion(unsigned char* key, unsigned char w[][4][4]);  //密钥扩展
	unsigned char FFmul(unsigned char a, unsigned char b);

	void SubBytes(unsigned char state[][4]);       //字节代换
	void ShiftRows(unsigned char state[][4]);      //行移位
	void MixColumns(unsigned char state[][4]);     //列混淆
	void AddRoundKey(unsigned char state[][4], unsigned char k[][4]);   //轮密钥加

	void InvSubBytes(unsigned char state[][4]);    //逆字节代换
	void InvShiftRows(unsigned char state[][4]);   //逆行移位
	void InvMixColumns(unsigned char state[][4]);  //逆列混淆
};

#endif // !defined(AFX_AES_H__6BDD3760_BDE8_4C42_85EE_6F7A434B81C4__INCLUDED_)
