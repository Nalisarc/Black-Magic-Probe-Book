const char bmflash_help[] = {
  "# BlackMagic Flash Programmer\n"
  "\n"
  "This utility downloads firmware into a micro-controller using the\n"
  "Black Magic Probe. It automatically handles idiosyncrasies of some microcontroller\n"
  "families, and supports setting a serial number during the download (i.e. serialization).\n"
  "\n"
  "At the top of the main window, you can select the target firmware file to download\n"
  "into the microcontroller. Below that, are panels for general options and serialization\n"
  "settings. The utility supports ELF files, Intel HEX files and raw binary files.\n"
  "\n"
  "The ELF and HEX files formats record at which addresses the data must be stored,\n"
  "but the BIN file is a flat binary file. It can be downloaded to any address in\n"
  "the microcontroller. When selecting a BIN file as the target file, a text field\n"
  "for the base address appears. If you leave the the address field empty, the\n"
  "firmware is downloaded to the base address of Flash memory of the microcontroller.\n"
  "\n"
  "To start a download, you can also use function key F5.\n"
  "\n"
  "More information:\n"
  " [[Options]]\n"
  " [[Serialization]]\n"
  " [[Tools]]\n"
  " [[About BlackMagic Flash Programmer]]\n"
  "\n"
  "# Options\n"
  "\n"
  "Various options can be set for the target. The utility saves these options per\n"
  "target (firmware) file. So you can use different options for separate projects.\n"
  "\n"
  "*Black Magic Probe*\n"
  ": This field is typically pre-selected, if you only have a single probe connected\n"
  " to USB. When you have multiple probes connected at the same time, you need to\n"
  " select the appropriate one from the drop-down list.\n"
  "\n"
  ": If you have a ctxLink probe configured for Wi-Fi, you need to select \"TCP/IP\"\n"
  " from the drop-down list.\n"
  "\n"
  "*IP Address*\n"
  ": This option is only visible when \"TCP/IP\" is selected from the drop-down list\n"
  " of the \"Black Magic Probe\" option. Here, you can fill in the IP address that\n"
  " the debug probe (likely a ctxLink probe) is configured at. Alternatively,\n"
  " you can click on the \"...\" button at the right of the edit field, to let the\n"
  " utility scan the network for the debug probe.\n"
  "\n"
  "*Code Read Protection*\n"
  ": This option allows you to protect the firmware from being read out of the\n"
  " microcontroller. It is currently supported for the NXP \"LPC\" family and the\n"
  " STMicroelectronics \"STM32\" family.\n"
  "\n"
  ": When this option is selected, you can choose one of three levels. For the STM32\n"
  " family, only levels 1 and 2 are valid. Please see the microcontroller's reference\n"
  " guide for the effect of each level. For the \"LPC\" microcontrollers, the firmware\n"
  " needs to prepared for code read protection. See the documentation from NXP and\n"
  " the book \"Embedded Debugging with the Black Magic Probe\" for more information.\n"
  "\n"
  ": Note: on many microcontrollers, code protection only becomes in effect after\n"
  " a power-cycle.\n"
  "\n"
  "*Power Target*\n"
  ": This option can be set to drive the power-sense pin with 3.3V (to power the\n"
  " target).\n"
  "\n"
  "*Full Flash Erase before download*\n"
  ": This option erases all Flash sectors in the microcontroller, before proceeding with the\n"
  " download. If not set, only the Flash sectors for which there is new data get\n"
  " erased & overwritten. Note that you can also clear all Flash memory via the\n"
  " Tools button.\n"
  "\n"
  "*Reset Target during connect*\n"
  ": This option may be needed on some microcontrollers, especially if SWD pins get redefined.\n"
  "\n"
  "*Keep Log of downloads*\n"
  ": On each successful firmware download, the utility adds a record to a log file,\n"
  " with the date & time of the download, plus information of the target file (checksum,\n"
  " RCS \"ident\" string). This is especially useful in combination with serialization,\n"
  " for tracking the firmware version and the date of the download.\n"
  "\n"
  "*Show Download Time*\n"
  ": On completing a download, print the time that the download took (in the Status\n"
  " view).\n"
  "\n"
  "*Post-process*\n"
  ": A post-processing script is run after every download, with information on the\n"
  " target file and the serial number (if serialization) is active. The script must be\n"
  " in the Tcl language. See the book \"Embedded Debugging with the Black Magic Probe\"\n"
  " for more information on scripting.\n"
  "\n"
  ": By default, the utility runs the script only after each successful download (so,\n"
  " not after a failed download). The option \"Post-process on failed downloads\" runs\n"
  " the script on every download. The status of the download (success or failure)\n"
  " is passed onto the script.\n"
  "\n"
  "---\n"
  "See also:\n"
  " [[Serialization]]\n"
  " [[Tools]]\n"
  " [[About BlackMagic Flash Programmer]]\n"
  "\n"
  "# Serialization\n"
  "\n"
  "Each firmware download can store an incremental serial number in the firmware.\n"
  "It does this by patching the target file on the flight, while it downloads to the\n"
  "microcontroller (the original ELF/HEX/NIN file is not changed).\n"
  "\n"
  "The serialization method is either \"No serialization\", \"Address\" or \"Match\".\n"
  "\n"
  "*No serialization*\n"
  ": Serialization is disabled.\n"
  "\n"
  "*Address*\n"
  ": This option stores the serial number at a specific address.\n"
  "\n"
  ": If the target file is an ELF file, you specify the name of a section in the\n"
  " ELF file, plus the offset from the start of the section. If you leave the field\n"
  " of the section empty, the offset is the absolute address (in the memory space\n"
  " of the microcontroller). The offset is interpreted as a hexadecimal value.\n"
  "\n"
  ": If the target file is in HEX or BIN formats, the section name is ignored, and\n"
  " the address is always an absolute address.\n"
  "\n"
  "*Match*\n"
  ": This option searches for a text or byte pattern in the target file, and replaces\n"
  " it with the serial number.\n"
  "\n"
  ": You give a pattern to match and an optional prefix. When the pattern is found,\n"
  " it is overwritten by the prefix, immediately followed the serial number.\n"
  "\n"
  ": The match and prefix strings may contain \\\\### and \\\\x## specifications (where\n"
  " \"#\" represents a decimal or hexadecimal digit) for non-ASCII byte values. It\n"
  " may furthermore contain the sequence \\U* to interpret the text that follows as\n"
  " Unicode, or \\A* to switch back to ASCII. When a literal \\\\ is part of the\n"
  " pattern, it must be doubled, as in \\\\\\\\.\n"
  "\n"
  "*Serial*\n"
  ": The serial number is a decimal value. It is incremented after each successful\n"
  " download.\n"
  "\n"
  "*Size*\n"
  ": The size of the serial number is in bytes. The serial number is padded with\n"
  " zeroes to fill up the size. Note that the prefix is part of the size.\n"
  "\n"
  ": For example, if the serial number is 12, the size is 8 and the format is ASCII\n"
  " (and there is no prefix), the string stored is 00000012. But if the format is\n"
  " Unicode, where each character takes two bytes, 0012 would be stored. And if\n"
  " the format is binary, there would be 7 bytes with a zero value stored, followed\n"
  " by a single byte with the value 12.\n"
  "\n"
  "*Format*\n"
  ": The format that the serial number is written in. It can be chosen as binary,\n"
  " ASCII or Unicode. In the latter two cases, the serial number is stored as\n"
  " readable text.\n"
  "\n"
  ": Note that in the case of Unicode text, each character takes two bytes (the size\n"
  " of the serial number is in bytes).\n"
  "\n"
  "*Increment*\n"
  ": The value by which the serial number is incremented after a successful download.\n"
  " It is typically 1, but it may be any value.\n"
  "\n"
  "*File*\n"
  ": By default, the settings for serialization are linked to the target file.\n"
  " However, when you want to share the serialization settings (and the serial\n"
  " number sequence) between two or more target files, you can specify a file in this\n"
  " field, where the serialization settings will be written to. Note that you need\n"
  " to set this field to the same filename for both projects.\n"
  "\n"
  "# Tools\n"
  "\n"
  "The \"Tools\" button pops up a menu with a few auxiliary actions.\n"
  "\n"
  "*Re-scan Probe List*\n"
  ": If a Black Magic Probe was not detected on start-up, and you connected one\n"
  " afterwards, you may use this option to re-scan for available probes.\n"
  "\n"
  "*Verify Download*\n"
  ": Compare the contents of Flash memory to the selected target file. Note that\n"
  " only the memory range that is valid in the target file is checked. Contents of\n"
  " Flash memory outside the range of the ELF/HEX/BIN file are ignored.\n"
  "\n"
  "*Erase Option Bytes*\n"
  ": On microcontrollers that support option bytes, you can use this command to\n"
  " clear the option bytes. If Code-Read Protection was set in the option bytes,\n"
  " clearing the option bytes will also erase all Flash memory.\n"
  "\n"
  ": A power-cycle may be required for the microcontroller to reload the option\n"
  " bytes.\n"
  "\n"
  "*Full Flash Erase*\n"
  ": Erase all Flash memory of the target microcontroller.\n"
  "\n"
  "*Blank Check*\n"
  ": Verifies that the Flash memory of the microcontroller is completely emty.\n"
  "\n"
  "*Dump Flash to File*\n"
  ": Writes the contents of Flash memory to a flat binary file. The file is trimmed\n"
  " to the portion of Flash memory that has data. Trailing empty Flash sectors are\n"
  " not saved.\n"
  "\n"
  "# About BlackMagic Flash Programmer\n"
  "\n"
  "The BlackMagic Flash utility is a companion tool of the book \"Embedded Debugging\n"
  "with the Black Magic Probe.\" More information on the utility and its use, can be\n"
  "found in this book. It is available as a free PDF file, and as a printed book.\n"
  "\n"
  "The utility requires a debug probe that is compatible with the Black Magic Probe.\n"
  "It is a self-contained utility; it does not require GDB.\n"
  "\n"
  "---\n"
  "Version 1.2.6986 \\\n"
  "Copyright 2019-2023 CompuPhase \\\n"
  "Licensed under the Apache License version 2.0\n"
  "\n"
};
