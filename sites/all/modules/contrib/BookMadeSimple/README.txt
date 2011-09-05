= Installation =

  # Extract du zip file in the modules directory 
  # Enable the module in the admin settings

= Configuration =

  # Go to Book Made Simple settings and :
	- Select content types that will populate the child drop down list in book links.
	- Select content types to auto create main book page when creating. 
  # Or edit a content type and check or uncheck Auto create book main page and Allow content type as child of book

= Use =

This module will create a main book page for content type selected in BookMadeSimple settings. This is a shortcut to create a node and click on Update book outline.

A dropdown listbox will be add in books links. Selecting a content type will add it as a child page of the book page.

= Tips =

To hide standard Add child page on links, add this line in your css file : 

	li.book_add_child a{display:none;}

To place dropdown listbox top of links, add this lines in your template.php file : 

	function <your template>_links($links, $attributes = array('class' => 'links')) {
		if (array_key_exists("book_made_simple",$links)) {
			$a = $links["book_made_simple"];
			unset($links["book_made_simple"]);
			array_unshift($links,$a);
		}
		return theme_links($links, $attributes = array('class' => 'links'));
	}

= Permissions =
BMS has two user permissions :

   # Show reoder book link : Visibility of the Reorder book link
   # Hide core outline links : Hide or show the core outline links of the book module.
 