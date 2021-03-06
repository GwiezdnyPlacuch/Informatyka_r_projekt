#pragma once

#include "wx/wx.h"
#include "Zadania.h"


class cMain : public wxFrame
{
public:
	cMain();
	~cMain();

	wxDECLARE_EVENT_TABLE();

	Zadania* task = new Zadania;

	wxChoice* choice_task = nullptr; //wybor dzialania
	
	wxPanel* panel = nullptr;
	
	wxChoice* choice1 = nullptr; //cezar czy vigenere
	wxChoice* choice2 = nullptr; //szyfruj czy deszyfruj
	wxTextCtrl* textCtrl1 = nullptr; //input text 1
	wxTextCtrl* textCtrl2 = nullptr; //input text 2
	wxButton* submit = nullptr;
	wxListBox* list = nullptr;
	

	void OnCipherSubmitButtonClick(wxCommandEvent& evt);
	void OnChoiceChange(wxCommandEvent& evt);
	void OnAnagramSubmitButtonClick(wxCommandEvent& evt);
	void OnPalindromeSubmitButtonClick(wxCommandEvent& evt);
	void OnONPSubmitButtonClick(wxCommandEvent& evt);
};

