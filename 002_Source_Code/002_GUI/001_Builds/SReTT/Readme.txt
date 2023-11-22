# Software REquirements Tracing Tool (SReTT)

The Software Requirements Tracing Tool (SReTT) is a tool that analyzes a complete software project and
parses a defined specification document in search for software requirements.

## Installation
- Download the latest 32-bit LabVIEW RunTime Engine from:
  https://www.ni.com/en/support/downloads/software-products/download.labview-runtime.html#484336
- Make sure your system has Python 3.9 installed.
- Copy, paste and unzip the SReTT.zip file to any local directory.


## Launch and Configuration
- Launch the SReTT.exe
- Wait for the splash screen to finish loading dependencies.
- On the left side, click the Settings button.
- Click on the folder icon from the Requirements Definition Directory.
- Browse your filesystem and go to <SReTT_Directory/Dependencies/Project_Requirements> and click select folder.
- Click on the folder icon from the Project Source Code Directory.
- Browse your filesystem and go to <SReTT_Directory/Dependencies/Project_Source_Code> and click select folder.
- Click on the folder icon from the Report Generation Directory.
- Browse your filesystem and go to <SReTT_Directory/Dependencies/Reports> and click select folder.
- Click the SAVE button at the bottom right corner of the settings panel.
- A pop-up message with indicate that the path locations have been saved.


## Execution
- On the left side, click the Analyzer button.
- Click the START button and wait for results to be displayed in the panel.
- If you desire to search for a single word, select the Word/Phrase option from the drop down list and type the
  word or requirement to search for and click START.


## Report Generation
- Once the information has been displayed, click the SAVE button right beside the START button to generate the report.


## Special Notes
- You can create your own set of Requirement documents. Important things are: Object_Identifier column and the c_Maturity
  column. Make sure your requirements are in the Object_Identifier column and marked as project_accepted in the c_Maturity 
  column.

