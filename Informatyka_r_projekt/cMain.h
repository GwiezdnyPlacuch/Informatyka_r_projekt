#pragma once

#include "wx/wx.h"
#include "Zadania.h"
#include <string>

class cMain : public wxFrame
{
public:
	cMain();
	~cMain();

	Zadania* task = new Zadania;

	wxChoice* choice_task = nullptr; //wybor dzialania
	
	wxPanel* panel = nullptr;
	
	wxChoice* choice_k = nullptr; //cezar czy vigenere
	wxChoice* choice_l = nullptr; //szyfruj czy deszyfruj
	wxTextCtrl* phrase = nullptr;
	wxTextCtrl* key_k = nullptr;
	wxButton* submit = nullptr;
	wxListBox* list = nullptr;
	

	void OnCipherSubmitButtonClick(wxCommandEvent& evt);
	void OnChoiceChange(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();

};

