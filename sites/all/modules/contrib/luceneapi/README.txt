
-- OVERVIEW --

Search Lucene API adds Solr-like search functionality to Drupal. Because it is
built on top of the Zend Framework's PHP port of Lucene, neither Java nor any
external services are required to use the module. Out of the box, the bundled
Search Lucene Content module adds advanced features that the core content search
lacks such as advanced Lucene query syntax, fielded sorting of search results,
and finer-grained content bias settings. Search Lucene API also has the ability
to integrate with existing Drupal word stemmers such as the Porter-Stemmer
project, but unlike the core search module it correctly highlights the matches.
Enabling the bundled Search Lucene Facets module adds faceted searching to your
site, and the exposed hooks allow developers to add additional Lucene fields and
facets with ease. Because Search Lucene API caches search results and facet
displays, repeated queries are returned instantly with little resource
consumption.


-- LUCENE --

Lucene is a high-performance, full-featured text search engine library. Although
Lucene is written in Java, ports for many languages exist including PHP. Unlike
the core Drupal search module, Lucene indexes are file based and are not
dependent on the database. Lucene also supports advanced query syntax such as
wildcard searches, fuzzy searches, and proximity searches. Visit the handbook
page at http://drupal.org/node/375446 for a full list of what Lucene has to
offer.


-- MODULES --

- Search Lucene API

Search Lucene API provides common functionality for modules that use Lucene as a
backend for search. Installed by itself, Search Lucene API does not index any
content nor does it provide a search interface. It does allow administrators to
alter global settings such as minimum word length, stop words, and logging.
Search Lucene API depends on the core Search module as it implements and extends
the core Search API.

- Search Lucene Content

Search Lucene Content indexes the nodes in a Drupal installation and provides a
search interface similar to the core Drupal Search module. Search Lucene Content
is intended to replace the core Drupal search, and it provides options to hide
the "Content" search tab and prevent the core Search from indexing any nodes.

-- API --

Search Lucene API exposes a series of hooks that allow developers to extend the
modules. All available hooks are defined in the *.api.php files in the modules'
directories, and there are many working examples of hook implementations in the
core codebase. In addition, contributed modules are available for download on
http://drupal.org that implement the API to provide additional functionality.
