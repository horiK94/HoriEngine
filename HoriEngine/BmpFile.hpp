#pragma once
#include <cstdio>
#include <fstream>
#include <iostream>
#include <locale>

using namespace HoriEngine::Debug;
using namespace HoriEngine::String;

namespace HoriEngine::Image
{
	class BmpFile
	{
	public:
		BmpFile(std::string fileName)
		{
			std::ifstream ifs(fileName, std::ios_base::binary);		//�o�C�i�����[�h�ŊJ��
			if (!ifs)
			{
				OutputDebug(U"file not Opened");
				return;
			}

			//�ŏ���0��seek(�ǂݎ��ʒu)������
			ifs.seekg(0, std::ios_base::end);		//�ǂݎ��ʒu���I�[�܂ōs��. 2�o�C�g�̃e�L�X�g�Ȃ�seek(�ǂݎ��ʒu)��2�ɂȂ�
			std::size_t size = ifs.tellg();		//�t�@�C���̐擪���牽�{�Ɛi�񂾂� = �T�C�Y�擾
			OutputDebug(U"file Opened: " + ToString(size));

			ifs.seekg(0, std::ios_base::beg);
			std::vector<char> buffer(2);
			ifs.read(buffer.data(), buffer.size());

			if(buffer[0] == 0x42 && buffer[1] == 0x4D)
			{
				OutputDebug(U"file is BMP");
			}
			else
			{
				OutputDebug(U"file is not BMP");
			}
		}
	};

}
