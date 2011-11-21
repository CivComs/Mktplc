                    The Civic Commons Marketplace
                    =============================

The Civic Commons Marketplace at http://marketplace.civiccommons.org/
is a Drupal-based web service that helps government technologists and
vendors "find out what's working, where".  It is a cooperatively
maintained database of information about the software used by
government entities.  It shows:

  1) What a given piece of civic software is and does,
  2) Where it's deployed or has been deployed,
  3) Who offers installation, support, and development services for it,
  4) Where its development community is (if open-source or similar)

This tree holds the software that powers the Marketplace itself.  By
publishing the code under an open source license, we hope to enable
interested Marketplace users to contribute bugfixes and improvements
back to the central site.  Naturally, releasing the code also means
anyone can deploy the Marketplace as an application, but assuming the
data at http://marketplace.civiccommons.org/ is well-curated, then
there should be no reason to deploy other instances of that data set,
except for development purposes.

For more information, see the "CC Mktplc Data Architecture" document,
which is (as of Nov 2011) still very much in progress:

  https://docs.google.com/a/nuams.co/document/d/15ThJvJ2exUJzi7rp9tVZrpbtkuzVr-EIrzLBl8xPeEI/edit?pli=1

The rest of this file is just the standard Drupal 7.7 README.txt,
since the process of deploying the Marketplace is pretty much the
process for deploying Drupal.  We'll add Marketplace-specific
information here as we find time and need.  Documentation patches are
always welcome, of course.

The project's master repository is: https://github.com/CivComs/Mktplc

======== Standard Drupal 7.7 README.txt follows ========

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
