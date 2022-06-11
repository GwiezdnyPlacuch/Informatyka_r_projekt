#include "cApp.h"

wxIMPLEMENT_APP(cApp);


cApp::cApp() {};
cApp::~cApp() {};

bool cApp::OnInit() {
	frame = new cMain();
	frame->SetWindowStyle(wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX));
	frame->Show();
	return true;
}