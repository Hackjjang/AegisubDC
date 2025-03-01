// Copyright (c) 2014, Thomas Goyne <plorkyeran@aegisub.org>
//
// Permission to use, copy, modify, and distribute this software for any
// purpose with or without fee is hereby granted, provided that the above
// copyright notice and this permission notice appear in all copies.
//
// THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
// WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
// ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
// WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
// ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
// OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
//
// Aegisub Project http://www.aegisub.org/

#include <libaegisub/signal.h>

class wxStyledTextCtrl;
class wxStyledTextEvent;

class TextSelectionController {
	long selection_start = 0;
	long selection_end = 0;
	long insertion_point = 0;
	bool changing = false;
	bool use_stc;
	wxTextEntryBase* ctrl_te = nullptr;
	wxControl* ctrl_ctl = nullptr;

	void UpdateUI(wxEvent& evt);

	agi::signal::Signal<> AnnounceSelectionChanged;

public:
	void SetSelection(long start, long end);
	void SetInsertionPoint(long point);

	long GetSelectionStart() const { return selection_start; }
	long GetSelectionEnd() const { return selection_end; }
	long GetInsertionPoint() const { return insertion_point; }

	void SetControl(wxStyledTextCtrl* ctrl);
	void SetControl(wxTextCtrl* ctrl);
	~TextSelectionController();

	DEFINE_SIGNAL_ADDERS(AnnounceSelectionChanged, AddSelectionListener)
};