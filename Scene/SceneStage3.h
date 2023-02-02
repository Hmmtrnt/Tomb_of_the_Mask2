// �X�e�[�W3
#pragma once
#include "SceneBase.h"
#include "../Util/common.h"

class GameManager;

class SceneStage3 : public SceneBase
{
public:
	SceneStage3();
	virtual ~SceneStage3();

	virtual void init();			// ������
	virtual void end();				// �I��
	virtual SceneBase* update();	// �X�V
	virtual void draw();			// �`��

private:
	// �Q�[���}�l�[�W���[�|�C���^
	GameManager* m_pManager;

	// �t���[���J�E���g
	int m_frameCount;
};
