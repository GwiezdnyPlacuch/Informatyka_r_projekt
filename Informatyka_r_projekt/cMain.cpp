#include "cMain.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
	EVT_CHOICE(1, cMain::OnChoiceChange)
wxEND_EVENT_TABLE()




cMain::cMain() : wxFrame(
	nullptr, //brak rodzica
	wxID_ANY,
	"Projekt Informatyka_r",
	wxPoint(30,30),
	wxSize(500,500) //rozmiar
	)
{
	choice_task = new wxChoice(this, 1, wxPoint(10, 10), wxSize(160, 30));
	choice_task->Append("Szyfrowania"); //0
	choice_task->Append("Anagramy"); //1
	choice_task->Append("Palindromy"); //2

	panel = new wxPanel(this,16,wxPoint(0,0),wxSize(500,500));
	
	
	
};

cMain::~cMain() {
	delete task;
};


void cMain::OnChoiceChange(wxCommandEvent& evt) {
	panel->DestroyChildren();
	switch (choice_task->GetSelection()) {
	case 0: { //szyfrowanie
		choice_k = new wxChoice(panel, wxID_ANY, wxPoint(10, 50), wxSize(160, 30));
		choice_k->Append("Cezar"); //0
		choice_k->Append("Vigenere"); //1

		choice_l = new wxChoice(panel, wxID_ANY, wxPoint(180, 50), wxSize(160, 30));
		choice_l->Append("Szyfruj"); //0
		choice_l->Append("Deszyfruj"); //1

		phrase = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(10, 90), wxSize(330, 30));
		key_k = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(10, 130), wxSize(330, 30));

		submit = new wxButton(panel, wxID_ANY, "Szyfruj", wxPoint(10, 170), wxSize(105, 30));
		submit->Connect(wxEVT_BUTTON, wxCommandEventHandler(cMain::OnCipherSubmitButtonClick), NULL, this);

		list = new wxListBox(panel, wxID_ANY, wxPoint(10, 210), wxSize(330, 30));
		break;
	}
	}

	evt.Skip();
}

void cMain::OnCipherSubmitButtonClick(wxCommandEvent& evt) {
	list->Clear();
	switch (choice_l->GetSelection()) {
	case 0: { //szyfruj
		switch (choice_k->GetSelection()) {
		case 0: //cezar
			int k;
			key_k->GetValue().ToInt(&k);
			list->Append(task->encryptC(phrase->GetValue(),k));
			break;
		case 1: //vigenere
			list->Append(task->encryptV(phrase->GetValue(), key_k->GetValue()));
			break;

		}
		break;
	}
	case 1: { //deszyfruj
		switch (choice_k->GetSelection()) {
		case 0: //cezar
			int k;
			key_k->GetValue().ToInt(&k);
			list->Append(task->decryptC(phrase->GetValue(), k));
			break;
		case 1: //vigenere
			list->Append(task->decryptV(phrase->GetValue(), key_k->GetValue()));
			break;

		}
		break;
	}
	}
	
	evt.Skip();
};


