READ ME for IPViewer

This is the read me file for IP Viewer.

Current Version is 4.0

This was a major upgrade so I decided to move it to 4.0. I never thought this little side project would get as big as it has. I had to get rid of log4cpp it just wasn't working as was causing all sorts of compiler warnings because the code is so old and uses deprecated functions. I lost a lot of flexibility but for now you can log to an output file if you wish. I will be adding more functionality in the future but for now it's working as expected.


Version is 3.2

This is a minor point upgrade.  Localization for German was added to the application and the logging was switched from basic file writing to use log4cpp.  This added rolling log file support and made the logging much more reliable and robust.

To achieve this the output filename was removed from the settings and placed into the log4cpp config file called log4cpp.properties.  There are two filenames one for error logging and one for ip information logging.  Either one can be modified from the default location.  If desired other settings can be changed but by default rolling flat file logging is performed.


http://log4cpp.sourceforge.net/

Version 3.1

This was a minor point upgrade that fixes a few bugs and also added localization for Simplified Chinese, Japanese, French, and Russian to the application.


Version 3.0.1

This was a major upgrade and adds support to view data about all the adapters on a system.  
Most systems will only have 1 or 2 adapters LAN/Wireless but some have Virtual adapters, etc.  
This upgrade allows for viewing all the ip addresses for all adapters.  More information about
the adapter has also been added.


Version 2.1

Added ability to log the ip information being collected.


Version 2.0

A bug was found in the external ip address that was trimming the last two digits.


Version 1.9

New installers were uploaded since the file version numbers had gotten out of synch on the help
pages and the shortcuts.

Fixed a bug with external ip address.

Currently after installation if you can't get your external ip address make
sure the installation folder has write permissions by everyone.


Version 1.8

Added ability to view external ip address.
Added ability to determine if external ip address should be checked for.