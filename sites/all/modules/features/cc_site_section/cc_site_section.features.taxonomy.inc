<?php
/**
 * @file
 * cc_site_section.features.taxonomy.inc
 */

/**
 * Implementation of hook_taxonomy_default_vocabularies().
 */
function cc_site_section_taxonomy_default_vocabularies() {
  return array(
    'site_section' => array(
      'name' => 'Site Section',
      'machine_name' => 'site_section',
      'description' => 'Specific sections of the site.',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
