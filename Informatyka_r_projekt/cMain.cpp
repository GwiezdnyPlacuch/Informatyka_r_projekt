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
	choice_task->Append("ONP"); //3

	panel = new wxPanel(this,16,wxPoint(0,0),wxSize(500,500));
	
};

cMain::~cMain() {
	//usuwaniem wskaznikow z wxWidgets zajmuje sie on sam
	//zeby uniknac bledow, nie ma czego usuwac
	//nie ma wycieku pamieci
	delete task;
};


void cMain::OnChoiceChange(wxCommandEvent& evt) {
	panel->DestroyChildren();
	switch (choice_task->GetSelection()) {
	case 0: { //szyfrowanie
		choice1 = new wxChoice(panel, wxID_ANY, wxPoint(10, 50), wxSize(160, 30));
		choice1->Append("Cezar"); //0
		choice1->Append("Vigenere"); //1

		choice2 = new wxChoice(panel, wxID_ANY, wxPoint(180, 50), wxSize(160, 30));
		choice2->Append("Szyfruj"); //0
		choice2->Append("Deszyfruj"); //1

		textCtrl1 = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(10, 90), wxSize(330, 30));
		textCtrl2 = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(10, 130), wxSize(330, 30));

		submit = new wxButton(panel, wxID_ANY, "Szyfruj", wxPoint(10, 170), wxSize(105, 30));
		submit->Connect(wxEVT_BUTTON, wxCommandEventHandler(cMain::OnCipherSubmitButtonClick), NULL, this);

		list = new wxListBox(panel, wxID_ANY, wxPoint(10, 210), wxSize(330, 30));
		break;
	}
	
	case 1: {
		textCtrl1 = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(10, 50), wxSize(160, 30));
		textCtrl2 = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(180, 50), wxSize(160, 30));

		submit = new wxButton(panel, wxID_ANY, "Sprawdz", wxPoint(10, 90), wxSize(105, 30));
		submit->Connect(wxEVT_BUTTON, wxCommandEventHandler(cMain::OnAnagramSubmitButtonClick), NULL, this);

		list = new wxListBox(panel, wxID_ANY, wxPoint(10, 140), wxSize(330, 30));

		break;
	}
	case 2: {
		textCtrl1 = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(10, 50), wxSize(160, 30));

		submit = new wxButton(panel, wxID_ANY, "Sprawdz", wxPoint(10, 90), wxSize(105, 30));
		submit->Connect(wxEVT_BUTTON, wxCommandEventHandler(cMain::OnPalindromeSubmitButtonClick), NULL, this);

		list = new wxListBox(panel, wxID_ANY, wxPoint(10, 140), wxSize(330, 30));

		break;
	}
	case 3: {
		textCtrl1 = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(10, 50), wxSize(160, 30));

		submit = new wxButton(panel, wxID_ANY, "Policz", wxPoint(10, 90), wxSize(105, 30));
		submit->Connect(wxEVT_BUTTON, wxCommandEventHandler(cMain::OnONPSubmitButtonClick), NULL, this);

		list = new wxListBox(panel, wxID_ANY, wxPoint(10, 140), wxSize(330, 30));

		break;
	}
	}


	evt.Skip();
}

void cMain::OnCipherSubmitButtonClick(wxCommandEvent& evt) {
	list->Clear();
	switch (choice2->GetSelection()) {
	case 0: { //szyfruj
		switch (choice1->GetSelection()) {
		case 0: //cezar
			int k;
			textCtrl2->GetValue().ToInt(&k);
			list->Append(task->encryptC(textCtrl1->GetValue(),k));
			break;
		case 1: //vigenere
			list->Append(task->encryptV(textCtrl1->GetValue(), textCtrl2->GetValue()));
			break;

		}
		break;
	}
	case 1: { //deszyfruj
		switch (choice1->GetSelection()) {
		case 0: //cezar
			int k;
			textCtrl2->GetValue().ToInt(&k);
			list->Append(task->decryptC(textCtrl1->GetValue(), k));
			break;
		case 1: //vigenere
			list->Append(task->decryptV(textCtrl1->GetValue(), textCtrl2->GetValue()));
			break;

		}
		break;
	}
	}
	
	evt.Skip();
};

void cMain::OnAnagramSubmitButtonClick(wxCommandEvent& evt) {
	list->Clear();

	if (task->are_anagrams(textCtrl1->GetValue(), textCtrl2->GetValue())) {
		list->Append("To s¹ anagramy");
	}
	else {
		list->Append("To nie s¹ anagramy");
	}

	evt.Skip();
}

void cMain::OnPalindromeSubmitButtonClick(wxCommandEvent& evt) {
	list->Clear();

	if (task->are_palindrome(textCtrl1->GetValue())) {
		list->Append("To jest palindrom");
	}
	else {
		list->Append("To nie jest palindrom");
	}

	evt.Skip();
}

void cMain::OnONPSubmitButtonClick(wxCommandEvent& evt) {
	list->Clear();

	int k = task->ONP(textCtrl1->GetValue());
	wxString s = wxString::Format(wxT("%i"), k);

	list->Append(s);

	evt.Skip();
}