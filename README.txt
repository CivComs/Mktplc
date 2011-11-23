                    The Civic Commons Marketplace
                    =============================

The Civic Commons Marketplace at http://marketplace.civiccommons.org/
is a Drupal-based web service that helps government technologists and
vendors "find out what's working, where".  It is a cooperatively
maintained database of information about software used by governments
of all sizes.  The Marketplace shows:

  1) What a given civic software package does,
  2) Where it's deployed, or has been deployed,
  3) Who offers installation, support, and development services for it,
  4) Where its development community is (if open-source or similar)

This tree holds the software that powers the Marketplace itself.  By
publishing the code under an open source license, we hope to enable
interested Marketplace users to contribute bugfixes and improvements
back to the central site.  Naturally, releasing the code also means
anyone could deploy a Marketplace-like site themselves.  However, the
data at http://marketplace.civiccommons.org/ is actively curated, so
there should be little motivation to deploy other instances, except
temporary ones for development purposes.

--------------------------------------------
Reporting bugs, contributing to development:
--------------------------------------------

The bug tracker for the Civic Commons Marketplace is here:

  http://developer.civiccommons.org/projects/mktplc

Before reporting a bug, please:

  * Look in the bug tracker to see if the bug has already been reported.

  * Check to see if your bug can be reproduced on the staging server,
    http://dev.cc.warecorp.com/, where the deployed code is sometimes
    running a bit ahead of what's on the production server.

If you need a staging server account in order to test for the bug,
please register as you normally would; if for some reason that doesn't
work, file a ticket requesting an account.  Similarly, you should be
able to self-register for a Redmine account to file bug tickets.

To talk to people at Civic Commons in real time, find us in the IRC
channel #civiccommons on irc.freenode.net (see http://irchelp.org/ if
you're not familiar with IRC), or use http://civiccommons.org/contact.

--------------------------------------------------
Understanding the Marketplace's data architecture:
--------------------------------------------------

The "CC Mktplc Data Architecture" document, which is (as of Nov 2011)
still very much in progress:

  https://docs.google.com/a/nuams.co/document/d/15ThJvJ2exUJzi7rp9tVZrpbtkuzVr-EIrzLBl8xPeEI/edit?pli=1

==========================================================================

The rest of this file is just the standard Drupal 7.7 README.txt,
since the process of deploying the Marketplace is pretty much the
process for deploying Drupal.  We'll add Marketplace-specific
information as we find time and need.  Documentation patches are
always welcome, of course.

The project's master repository is: https://github.com/CivComs/Mktplc

================= Standard Drupal 7.7 README.txt follows =================

CONTENTS OF THIS FILE
---------------------

 * About Drupal
 * Configuration and features
 * Appearance
 * Developing for Drupal

ABOUT DRUPAL
------------

Drupal is an open source content management platform supporting a variety of
websites ranging from personal weblogs to large community-driven websites. For
more information, see the Drupal website at http://drupal.org/, and join the
Drupal community at http://drupal.org/community.

Legal information about Drupal:
 * Know your rights when using Drupal:
   See LICENSE.txt in the same directory as this document.
 * Learn about the Drupal trademark and logo policy:
   http://drupal.com/trademark

CONFIGURATION AND FEATURES
--------------------------

Drupal core (what you get when you download and extract a drupal-x.y.tar.gz or
drupal-x.y.zip file from http://drupal.org/project/drupal) has what you need to
get started with your website. It includes several modules (extensions that add
functionality) for common website features, such as managing content, user
accounts, image uploading, and search. Core comes with many options that allow
site-specific configuration. In addition to the core modules, there are
thousands of contributed modules (for functionality not included with Drupal
core) available for download.

More about configuration:
 * Install, upgrade, and maintain Drupal:
   See INSTALL.txt and UPGRADE.txt in the same directory as this document.
 * Learn about how to use Drupal to create your site:
   http://drupal.org/documentation
 * Download contributed modules to sites/all/modules to extend Drupal's
   functionality:
   http://drupal.org/project/modules
 * See also: "Developing for Drupal" for writing your own modules, below.

APPEARANCE
----------

In Drupal, the appearance of your site is set by the theme (themes are
extensions that set fonts, colors, and layout). Drupal core comes with several
themes. More themes are available for download, and you can also create your own
custom theme.

More about themes:
 * Download contributed themes to sites/all/themes to modify Drupal's
   appearance:
   http://drupal.org/project/themes
 * Develop your own theme:
   http://drupal.org/documentation/theme

DEVELOPING FOR DRUPAL
---------------------

Drupal contains an extensive API that allows you to add to and modify the
functionality of your site. The API consists of "hooks", which allow modules to
react to system events and customize Drupal's behavior, and functions that
standardize common operations such as database queries and form generation. The
flexible hook architecture means that you should never need to directly modify
the files that come with Drupal core to achieve the functionality you want;
instead, functionality modifications take the form of modules.

When you need new functionality for your Drupal site, search for existing
contributed modules. If you find a module that matches except for a bug or an
additional needed feature, change the module and contribute your improvements
back to the project in the form of a "patch". Create new custom modules only
when nothing existing comes close to what you need.

More about developing:
 * Search for existing contributed modules:
   http://drupal.org/project/modules
 * Contribute a patch:
   http://drupal.org/patch/submit
 * Develop your own module:
   http://drupal.org/developing/modules
 * Follow best practices:
   http://drupal.org/best-practices
 * Refer to the API documentation:
   http://api.drupal.org/api/drupal/7
