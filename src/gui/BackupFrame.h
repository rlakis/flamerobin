/*
  The contents of this file are subject to the Initial Developer's Public
  License Version 1.0 (the "License"); you may not use this file except in
  compliance with the License. You may obtain a copy of the License here:
  http://www.flamerobin.org/license.html.

  Software distributed under the License is distributed on an "AS IS"
  basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See the
  License for the specific language governing rights and limitations under
  the License.

  The Original Code is FlameRobin (TM).

  The Initial Developer of the Original Code is Michael Hieke.

  Portions created by the original developer
  are Copyright (C) 2004 Michael Hieke.

  All Rights Reserved.

  $Id$

  Contributor(s):
*/

//-----------------------------------------------------------------------------
#ifndef BACKUPFRAME_H
#define BACKUPFRAME_H

#include <wx/wx.h>

#include "BackupRestoreBaseFrame.h"

class BackupThread;
//-----------------------------------------------------------------------------
class BackupFrame: public BackupRestoreBaseFrame {
    friend class BackupThread;
public:
    // events
    void OnBrowseButtonClick(wxCommandEvent& event);
    void OnStartButtonClick(wxCommandEvent& event);

    BackupFrame(wxWindow* parent, Database* db);
private:
    void layoutControls();
    virtual void updateControls();
protected:
    virtual void doReadConfigSettings(const wxString& prefix);
    virtual void doWriteConfigSettings(const wxString& prefix) const;
    virtual const wxString getName() const;
protected:
    wxCheckBox* checkbox_checksum;
    wxCheckBox* checkbox_limbo;
    wxCheckBox* checkbox_metadata;
    wxCheckBox* checkbox_garbage;
    wxCheckBox* checkbox_transport;
    wxCheckBox* checkbox_extern;
    DECLARE_EVENT_TABLE()
};
//-----------------------------------------------------------------------------
#endif // BACKUPFRAME_H
