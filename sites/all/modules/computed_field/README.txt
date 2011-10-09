====================== The Computed Field Drupal Module ======================

Computed Field is a Field module that lets you add a computed field to custom
entities in Drupal. You can choose whether to store your computed field in the
database. You can also choose whether to display the field, and how to format
it. The value of the field is set using PHP code, so it can draw on anything
available to Drupal, including other fields, the current user, database
tables, etc. The drawback of this is, of course, is that you need to know some 
PHP to make use of it.

Computed Field requires the Field module. (As well as the Field UI module 
unless you are doing everything programatically)

==========================================
Usage
==========================================

Getting Started
--------------- 

Before you can use Computed Field, you'll need to enable the field module.
You will probably also want to enable the 'Field UI' module and other field 
modules, such as 'text','number', 'date', etc.

To add a computed field to a content type, go to Administer > Structure >
Content Types, select the content type you want to add to, and click on the
'Manage Fields' link. Here you will see an 'Add new field' form which you'll 
use to create a 'Computed' field from the pulldown. After hitting the "Save"
button you will be given a chance to initially configure this new computed
field.

==========================================
 Configuration
==========================================

A Computed Field can be configured with the usual field options, as well
as the following extra options:

Computed Code (PHP) -- This is the code that will assign a value to your 
computed field. It should be valid php without the <?php ?> tags.

Display Code (PHP) -- This is also PHP code which should assign a string to 
the $display_output variable. It has '$entity_field_item['value']' available, 
which is the value of the computed field.

Store using the database settings below -- If this is checked then the field
is computed on node save and stored in the DB. If it isn't stored then it will
be recomputed every time you view a node containing this field. DB storage is
also required if you want to use the field with the Views module.

Database Storage Settings:

	Data Type -- This is the sql data type to use to store the field.
	
	Data Length -- This value will simply be passed on to sql. For storing up
	to 10 digit INTs, enter 10. For storing currency as a float, use 10,2
	(unless you'll store larger than 10 figure amounts!).  For storing
	usernames or other short text with a varchar field, 64 may be appropriate.

	Default Value -- Leave this blank if you don't want the database to store
	a default value if your computed field's value isn't set.

	Not NULL -- Leave unchecked if you want to allow NULL values in the
	database field.

	Sortable  -- Used in Views to allow sorting a column of this field.
	
	Indexed -- Adds a simple DB index on on the computed values

==========================================
 Examples
==========================================

Here are a couple examples to get you started with Computed Field. 

Adding two other fields
----------------------- 

Imagine you have two existing number fields named field_product_price and
field_postage_price. Both are required fields, and you want to create a 
computed field (field_total_cost) which adds these two fields. Create a 
new computed field with the name field_total_cost, and in your computed 
field's configuration set the following:

- Computed Code (PHP):

$entity_field[0]['value'] =
$entity->field_product_price[LANGUAGE_NONE][0]['value'] +
$entity->field_postage_price[LANGUAGE_NONE][0]['value'];

- Display Code (PHP):

$display_output = '$' . $entity_field_item['value'];

- Check 'Store using the database settings below'

- Data Type: decimal

- Decimal Length: 10

- Decimal Precision: 2

- Default Value: 0.00

- Check 'Not NULL'


Calculating a Duration given a start and end time
-------------------------------------------------

This example uses KarenS' date module (http://drupal.org/project/date) to
calculate the difference between the 'start' datetime and 'end' datetime of
a Date field named "field_event_date". We will then display the output as a
decimal number of hours.

Computed field settings:

- Computed Code (PHP):

$start = strtotime($entity->field_event_date[LANGUAGE_NONE][0]['value']);
$end = strtotime($entity->field_event_date[LANGUAGE_NONE][0]['value2']);
$difference = ($end - $start);
$entity_field[0]['value'] = $difference/(60 * 60);

- Display Code (PHP):

$display_output = $entity_field_item['value'] . " hours";

- Check 'Store using the database settings below

- Data Type:</b> float

- Data Length:</b> 3,2

- Check 'Sortable'


==========================================
Programatically Specifying Computed Code
==========================================

Computed Field will also look for special function names you can define to 
create computed code outside of the normal admin field settings forms.

For COMPUTATION
---------------
The following function naming is used:

computed_field_(your_field_name)_compute()

Which takes in the following variables:

($entity_field, $entity_type, $entity, $field, $instance, $langcode, $items)

Your function should set the appropriate values to $entity_field.

For DISPLAY
-----------
The following function naming is used:

computed_field_(your_field_name)_display($field, $entity_field_item)

Your function should return the output to be displayed.