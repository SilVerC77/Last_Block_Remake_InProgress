/**
 * @file CDirectInput.cpp
 * @brief DirectInput�L�[�{�[�h�̃N���X
 * @author �D�ˁ@�엲
 * @date ���t�i2017.02.14�j
 */

#include "stdafx.h"
#include "CDirectInput.h"

std::shared_ptr<CDirectInput> CDirectInput::m_instance = NULL;	 //!< �y�N���X�ϐ��z

/**
 * Private Methods
 */
CDirectInput::CDirectInput()
{
}

CDirectInput::~CDirectInput()
{
}

/**
 * @fn HRESULT CDirectInput::init(HWND inHWnd)
 * @brief ������
 * @param hWnd_		WindowsAPI�E�C���h�E�n���h��
 * @return			WindowsAPI ���s����
 */
HRESULT CDirectInput::init(HWND inHWnd)
{
	m_pDinput = NULL;		 //!< DirectInput �I�u�W�F�N�g
	m_pKeyDevice = NULL;	 //!< �L�[�{�[�h
	m_pMouseDevice = NULL;	 //!< �}�E�X

	m_hWnd = inHWnd;

	ZeroMemory(&m_keyboardInput, sizeof(BYTE) * BUFFER_SIZE);		 //!< �L�[�{�[�h�̓��͏��
	ZeroMemory(&m_keyboardInputPrev, sizeof(BYTE) * BUFFER_SIZE);	 //!< �O��̃L�[�{�[�h�̓��͏��

	ZeroMemory(&m_pressed, sizeof(BYTE) * BUFFER_SIZE);		 //!< �����ꂽ
	ZeroMemory(&m_pressedOnce, sizeof(BYTE) * BUFFER_SIZE);	 //!< �����ꑱ����

	ZeroMemory(&m_diMouseState2, sizeof(DIMOUSESTATE2));	 //!< �}�E�X�̓��͏��
	ZeroMemory(&m_mouseInputPrev, sizeof(DIMOUSESTATE2));	 //!< �}�E�X�̓��͏��
	
	/**
	 * DirectInput�I�u�W�F�N�g�̐���
	 */
	if (FAILED(DirectInput8Create(GetModuleHandle(NULL),
		DIRECTINPUT_VERSION,
		IID_IDirectInput8,
		(VOID**)&m_pDinput,
		NULL))) {
		return E_FAIL;
	}
	/**
	 *�L�[�{�[�h�̏�����
	 *�L�[�{�[�h�̃f�o�C�X�I�u�W�F�N�g�̐���
	 */
	initKeyboard(inHWnd);
	
	// �}�E�X�̃f�o�C�X�I�u�W�F�N�g���쐬
	initMouse(inHWnd);

	return S_OK;
}

/**
* @fn HRESULT CDirectInput::initKeyboard(HWND inHWnd)
* @brief �L�[�{�[�h�̏�����
* @param hWnd_		WindowsAPI�E�C���h�E�n���h��
* @return			WindowsAPI ���s����
*/
HRESULT CDirectInput::initKeyboard(HWND inHWnd)
{
	if (FAILED(m_pDinput->CreateDevice(GUID_SysKeyboard, &m_pKeyDevice, NULL))) {
		return E_FAIL;
	}
	/**
	 *�f�o�C�X���L�[�{�[�h�ɐݒ�
	 */
	if (FAILED(m_pKeyDevice->SetDataFormat(&c_dfDIKeyboard))) {
		return E_FAIL;
	}
	/**
	 *�������x���̐ݒ�
	 */
	if (FAILED(m_pKeyDevice->SetCooperativeLevel(inHWnd, DISCL_NONEXCLUSIVE | DISCL_BACKGROUND))) {
		return E_FAIL;
	}
	/**
	 *���͐���J�n
	 */
	m_pKeyDevice->Acquire();
	return S_OK;
}

/**
* @fn HRESULT CDirectInput::initMouse(HWND inHWnd)
* @brief �}�E�X�̏�����
* @param hWnd_		WindowsAPI�E�C���h�E�n���h��
* @return			WindowsAPI ���s����
*/
HRESULT CDirectInput::initMouse(HWND inHWnd)
{
	if (FAILED(m_pDinput->CreateDevice(GUID_SysMouse, &m_pMouseDevice, NULL))) {
		return false;
	}
	// �f�[�^�t�H�[�}�b�g��ݒ�
	// �}�E�X�p�̃f�[�^�E�t�H�[�}�b�g��ݒ�
	if (FAILED(m_pMouseDevice->SetDataFormat(&c_dfDIMouse2))) {
		return E_FAIL;
	}
	// ���[�h��ݒ�i�t�H�A�O���E���h����r�����[�h�j
	if (FAILED(m_pMouseDevice->SetCooperativeLevel(inHWnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND))) {
		return E_FAIL;
	}
	//// �f�o�C�X�̐ݒ�
	DIPROPDWORD diprop;
	diprop.diph.dwSize = sizeof(diprop);
	diprop.diph.dwHeaderSize = sizeof(diprop.diph);
	diprop.diph.dwObj = 0;
	diprop.diph.dwHow = DIPH_DEVICE;
	diprop.dwData = DIPROPAXISMODE_REL;	// ���Βl���[�h�Őݒ�i��Βl��DIPROPAXISMODE_ABS�j

	if (FAILED(m_pMouseDevice->SetProperty(DIPROP_AXISMODE, &diprop.diph))) {
		return E_FAIL;
	}
	// ���͐���J�n
	m_pMouseDevice->Acquire();
	return S_OK;
}

/**
 * @fn VOID CDirectInput::free()
 * @brief DirectInput�̃I�u�W�F�N�g�̊J��
 * @param	����
 * @return	����
 */
VOID CDirectInput::free()
{
	if (m_pMouseDevice)
		m_pMouseDevice->Unacquire();
	SAFE_RELEASE(m_pMouseDevice);	 //!< �}�E�X

	if (m_pKeyDevice)
		m_pKeyDevice->Unacquire();
	SAFE_RELEASE(m_pKeyDevice);		//!< �L�[�{�[�h

	SAFE_RELEASE(m_pDinput);		//!< DirectInput �I�u�W�F�N�g
}

//__________________________________________________________________
// Public Methods
//__________________________________________________________________

/**
 * @fn std::shared_ptr<CDirectInput> CDirectInput::getInstance(HWND inHWnd)
 * @brief �C���X�^���X���擾 �y�N���X���\�b�h�z<Singleton-pattern>
 * @param inHWnd	�����̔z��
 * @return		�C���X�^���X
 */
std::shared_ptr<CDirectInput> CDirectInput::getInstance(HWND inHWnd)
{
	if (m_instance == NULL) {
		m_instance = shared_ptr<CDirectInput>(new CDirectInput());
		m_instance->init(inHWnd);
	}
	return m_instance;
}

/**
 * @fn VOID CDirectInput::releaseInstance()
 * @brief �C���X�^���X����� �y�N���X���\�b�h�z<Singleton-pattern>
 * @param	����
 * @return	����
 */
VOID CDirectInput::releaseInstance()
{
	m_instance->free();
}

/**
 * @fn HRESULT CDirectInput::getState()
 * @brief �L�[�{�[�h�E�}�E�X�̃X�e�[�^�X�̎擾
 * @param	����
 * @return   WindowsAPI ���s����
 */
//
HRESULT CDirectInput::getState()
{
	/**
	 *�L�[�{�[�h�̍X�V
	 */
	HRESULT hr = m_pKeyDevice->Acquire();

	if ((hr == DI_OK) || (hr == S_FALSE)) {
		memcpy(m_keyboardInputPrev, m_keyboardInput, sizeof(BYTE) * BUFFER_SIZE);	 //!<�O��̏�Ԃ�ޔ�

		m_pKeyDevice->GetDeviceState(sizeof(m_keyboardInput), &m_keyboardInput);	 //!<�L�[�{�[�h�̏�Ԃ��擾
		for (int i = 0; i < BUFFER_SIZE; i++) {
			if (IS_KEY_PRESSED(m_keyboardInput[i])) {
				if ((!m_pressedOnce[i]) && (!m_pressed[i])) {
					m_pressedOnce[i] = TRUE;		 //!< ���߂ĉ����ꂽ
					m_pressed[i] = TRUE;
				}
				else {
					m_pressedOnce[i] = FALSE;
				}
			}
			else {
				m_pressedOnce[i] = FALSE;
				m_pressed[i] = FALSE;
			}
		}
	}

	/**
	*�}�E�X�̏�Ԃ��擾���܂�
	*/
	memcpy(&m_mouseInputPrev, &m_diMouseState2, sizeof(DIMOUSESTATE2));	 //!<�O��̏�Ԃ�ޔ�
	hr = m_pMouseDevice->GetDeviceState(sizeof(DIMOUSESTATE2), &m_diMouseState2);
	if (hr == DIERR_INPUTLOST || hr == DIERR_NOTACQUIRED) {
		hr = m_pMouseDevice->Acquire();
		while (hr == DIERR_INPUTLOST)
			hr = m_pMouseDevice->Acquire();
	}

	return S_OK;
}

/**
 * @fn BOOL CDirectInput::isKeyPressed(BYTE aKey)
 * @brief �L�[�{�[�h�̉���
 * @param aKey	���ׂ�L�[
 * @return		�����ꂽ��
 */
BOOL CDirectInput::isKeyPressed(BYTE aKey)
{
	/**
	 *���݉����Ă���
	 */
	if (IS_KEY_PRESSED(m_keyboardInput[aKey]))
	{
		return TRUE;
	}
	return FALSE;
}

/**
 * @fn BOOL CDirectInput::isPressedOnce(BYTE aKey)
 * @brief �w�肳�ꂽ�L�[�̉�������x������
 * @param aKey	���ׂ�L�[
 * @return		�����ꂽ��
 */
BOOL CDirectInput::isPressedOnce(BYTE aKey)
{
	return m_pressedOnce[aKey];
}

/**
* @fn BOOL CDirectInput::isKeyTrigger(BYTE aKey)
* @brief  �w�肳�ꂽ�L�[�̃g���K�[
* @param aKey	���ׂ�L�[
* @return		�O�񉟂��Ă��Č��݉����Ă���
*/
BOOL CDirectInput::isKeyTrigger(BYTE aKey)
{
	/**
	 *�O�񉟂��Ă��Č��݉����Ă���
	 */
	if ((IS_KEY_PRESSED(m_keyboardInputPrev[aKey])) && (IS_KEY_PRESSED(m_keyboardInput[aKey])))
	{
		return TRUE;
	}
	return FALSE;
}

/**
 * @fn BOOL CDirectInput::isKeyReleased(BYTE aKey)
 * @brief  �w�肳�ꂽ�L�[�̃`�F�b�N
 * @param aKey	���ׂ�L�[
 * @return		�O�񉟂��Ă��Č��ݗ����Ă���
 */
BOOL CDirectInput::isKeyReleased(BYTE aKey)
{
	/**
	 *�O�񉟂��Ă��Č��ݗ����Ă���
	 */
	if ((IS_KEY_PRESSED(m_keyboardInputPrev[aKey])) && !(IS_KEY_PRESSED(m_keyboardInput[aKey])))
	{
		return TRUE;
	}
	return FALSE;
}

/**
* @fn BOOL CDirectInput::isLeftButtonClicked()
* @brief  �}�E�X�̍��{�^���̃`�F�b�N
* @return		�����Ă���
*/
BOOL CDirectInput::isLeftButtonClicked()
{
	if ((IS_KEY_PRESSED(m_diMouseState2.rgbButtons[0])))
	{
		return TRUE;
	}
	return FALSE;
}
/**
* @fn BOOL CDirectInput::isRightButtonClicked()
* @brief  �}�E�X�̉E�{�^���̃`�F�b�N
* @return		�����Ă���
*/
BOOL CDirectInput::isRightButtonClicked()
{
	if ((IS_KEY_PRESSED(m_diMouseState2.rgbButtons[1])))
	{
		return TRUE;
	}
	return FALSE;
}

/**
* @fn BOOL CDirectInput::isCenterButtonClicked()
* @brief  �}�E�X�̒��{�^���̃`�F�b�N
* @return		�����Ă���
*/
BOOL CDirectInput::isCenterButtonClicked()
{
	if ((IS_KEY_PRESSED(m_diMouseState2.rgbButtons[2])))
	{
		return TRUE;
	}
	return FALSE;
}

/**
* @fn BOOL CDirectInput::isLeftButtonReleased()
* @brief  �}�E�X�̍��{�^���̃`�F�b�N
* @return		�O�񉟂��Ă��Č��ݗ����Ă���
*/
BOOL CDirectInput::isLeftButtonReleased()
{
	/**
	 *�O�񉟂��Ă��Č��ݗ����Ă���
	 */
	if ((IS_KEY_PRESSED(m_mouseInputPrev.rgbButtons[0])) && !(IS_KEY_PRESSED(m_diMouseState2.rgbButtons[0])))
	{
		return TRUE;
	}
	return FALSE;
}

/**
* @fn BOOL CDirectInput::isRightButtonReleased()
* @brief  �}�E�X�̉E�{�^���̃`�F�b�N
* @return		�O�񉟂��Ă��Č��ݗ����Ă���
*/
BOOL CDirectInput::isRightButtonReleased()
{
	/**
	 *�O�񉟂��Ă��Č��ݗ����Ă���
	 */
	if ((IS_KEY_PRESSED(m_mouseInputPrev.rgbButtons[1])) && !(IS_KEY_PRESSED(m_diMouseState2.rgbButtons[1])))
	{
		return TRUE;
	}
	return FALSE;
}

/**
* @fn BOOL CDirectInput::isCenterButtonReleased()
* @brief  �}�E�X�̒��{�^���̃`�F�b�N
* @return		�O�񉟂��Ă��Č��ݗ����Ă���
*/
BOOL CDirectInput::isCenterButtonReleased()
{
	/**
	 *�O�񉟂��Ă��Č��ݗ����Ă���
	 */
	if ((IS_KEY_PRESSED(m_mouseInputPrev.rgbButtons[2])) && !(IS_KEY_PRESSED(m_diMouseState2.rgbButtons[2])))
	{
		return TRUE;
	}
	return FALSE;
}

/**
* @fn XMFLOAT2 CDirectInput::getMousePos()
* @brief  �}�E�X�̍��W�擾
* @return		���݂̃}�E�X�̍��W(���S��(0,0))
*/
XMFLOAT2 CDirectInput::getMousePos()
{
	XMFLOAT2 ret;
	POINT pos;
	GetCursorPos(&pos);
	ScreenToClient(m_hWnd, &pos);
	ret.x = pos.x - (float)(WINDOW_WIDTH / 2);
	ret.y = (float)(WINDOW_HEIGHT / 2) - pos.y;
	return ret;
}
