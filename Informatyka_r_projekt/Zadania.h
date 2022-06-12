#pragma once

#include "wx/wx.h"
#include <string>
#include <stack>

class Zadania
{
public:
    wxString encryptV(wxString t, wxString k);
    wxString decryptV(wxString t, wxString k);

    wxString encryptC(wxString t, int k);
    wxString decryptC(wxString t, int k);

    bool are_anagrams(wxString str1, wxString str2);
    bool are_palindrome(wxString str1);

    int ONP(wxString r);
};

