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
	
	wxChoice* choice1 = nullptr; //cezar czy vigenere
	wxChoice* choice2 = nullptr; //szyfruj czy deszyfruj
	wxTextCtrl* textCtrl1 = nullptr;
	wxTextCtrl* textCtrl2 = nullptr;
	wxButton* submit = nullptr;
	wxListBox* list = nullptr;
	

	void OnCipherSubmitButtonClick(wxCommandEvent& evt);
	void OnChoiceChange(wxCommandEvent& evt);
	void OnAnagramSubmitButtonClick(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();

};

