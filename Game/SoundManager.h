#pragma once
#include "sound/SoundSource.h"

//�t�@�C���p�X��ǉ�����ۂ́A
//cpp��namespace�Ɖ��L��enum��ǉ����Ă��������B
enum Sound {
	enSound_TitleBGM,
	enSound_InGameBGM,
	enSound_GameClearBGM,
	enSound_GameOverBGM,
	enSound_ItemGetSE,
	enSound_Num //���̃X�e�[�^�X�́A�T�E���h�̑�����\���Ă��邽�߁A���̉��ɂ͒ǉ����Ȃ��ł��������B
};

class SoundManager:public IGameObject
{
public:
	SoundManager();
	~SoundManager() {};
	/// <summary>
	/// �w�肵���T�E���h���Đ����A�Đ����̃T�E���h�\�[�X��Ԃ��܂��B
	/// </summary>
	/// <param name="number">�Đ�����T�E���h���w�肵�܂��B</param>
	/// <param name="isLoop">�T�E���h�����[�v�Đ����邩�ǂ������w�肵�܂��B�f�t�H���g�� true �ł��B</param>
	/// <param name="volume">�Đ����ʂ��w�肵�܂��B�f�t�H���g�� 1.0f �ł��B</param>
	/// <returns>�Đ����̃T�E���h�\�[�X�ւ̃|�C���^�B</returns>
	SoundSource* PlayingSound(Sound number, bool isLoop = true, float volume = 1.0f);
};

