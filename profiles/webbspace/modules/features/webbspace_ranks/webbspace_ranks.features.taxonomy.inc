<?php
/**
 * @file
 * webbspace_ranks.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function webbspace_ranks_taxonomy_default_vocabularies() {
  return array(
    'ranks' => array(
      'name' => 'Ranks',
      'machine_name' => 'ranks',
      'description' => 'Character ranks',
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
