<?php
/**
 * @file
 * webbspace_positions.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function webbspace_positions_taxonomy_default_vocabularies() {
  return array(
    'positions' => array(
      'name' => 'Positions',
      'machine_name' => 'positions',
      'description' => 'Positions on a ship',
      'hierarchy' => '1',
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
