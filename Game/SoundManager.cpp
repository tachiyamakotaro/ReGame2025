#include "stdafx.h"
#include "SoundManager.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"
#include <iostream>

namespace {
	//�t�@�C�����̂ݒǉ�����΁A
	//�R���X�g���N�^�ɂĎ�����g_soundEngine�ɓo�^����܂��B
	//��F"Assets/sound/"+"Title"+".wav"
	const char* SOUND_FILEPATH = "Assets/sound/";
	const char* SOUND_EXTENSION = ".wav";
	const char* soundFileNameList[enSound_Num] =
	{
		//�����Ƀt�@�C������ǉ����Ă��������B
		//�ǉ�����ۂ́A�w�b�_��enum Sound�ɂ��ǉ����Ă��������B
		"Title",
		"InGame",
		"GameClear",
		"GameOver",
		"ItemGet",
	};
}

SoundManager::SoundManager()
{
	//�T�E���h�̃t�@�C���p�X�̓o�^
	//�T�E���h�̌���(enSound_Num�̐�)�A�o�^����܂��B
	for (int i = 0; i < enSound_Num; i++)
	{
		//std::string���g�p���A�����������
		std::string file = std::string(SOUND_FILEPATH) + soundFileNameList[i] + (SOUND_EXTENSION);
		//������const char*�Ȃ̂ŁAstd::string����const char*�ɕϊ��B
		const char* filepath = file.c_str();
		//g_soundEngine�֓o�^�B
		g_soundEngine->ResistWaveFileBank(i, filepath);
	}
}

SoundSource* SoundManager::PlayingSound(Sound number, bool isLoop, float volume)
{
	SoundSource* sound = NewGO<SoundSource>(0);
	//�����Ŏ󂯎����number��soundFileNameList�̗v�f�ԍ��ɑΉ����Ă��܂��B
	sound->Init(number);
	sound->SetVolume(volume);
	sound->Play(isLoop);
	//�߂�l��SoundSource�̃C���X�^���X��ݒ�B
	//�Ăяo�����ŁA
	//SoundSource* sound = sound.PlayingSound(Sound::enSound_TitleBGM);
	//�Ə����ƃC���X�^���X�̃A�h���X���󂯎�邱�Ƃ��ł��܂��B
	return sound;
}