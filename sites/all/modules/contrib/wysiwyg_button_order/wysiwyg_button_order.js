// $Id$
/**
 * @file
 * Syncronizes the buttons checkboxes with the button order field.
 * Adds separators, removes buttons.
 */
(function ($) {
  Drupal.behaviors.WysiwygButtonOrder = {
    attach: function(context) {
      // add a button to add separators
      $('#buttonorder').parent().once().prepend(
        '<input type="button" class="form-submit" id="add-separator" value="' + Drupal.t('Add separator') + '" />'
        );
      $('#add-separator').once().click(function(e) {
        e.preventDefault();
        addDraggableRow('separator','---------------',Drupal.t('Separator'));
        return false;
      });

      // add events to remove links
      $('.removelink').once().click(function(e) {
        e.preventDefault();
        var split = $(this).parent().parent().attr('id').split('-');
        var group = $(this).parent().prev().prev().text();
        var name = split[1];
        if (name != 'separator') unCheckButton(name,group);
        removeDraggableRow($(this).parent().parent().attr('id'));
        return false;
      });

      // add events to sync button fieldset with order fieldset
      $('fieldset:nth-child(2) input.form-checkbox').once().click(function() {
        var split = $(this).attr('name').split('][');
        if (this.checked){
          addDraggableRow(split[1].slice(0,-1),split[0].substr(8),$(this).parent().text());
        } else {
          removeDraggableRow('order-' + split[1].slice(0,-1));
        }
      });

      /**
       * Creates draggable row for button
       * @args shortname: the short name of the button
       * @args group: the group name of the button belongs in
       */
      function addDraggableRow(name,group,fullname) {
        if ($('#buttonorder').length > 0) {
          // make a full row
          var row = createDraggableRow(name,group,fullname);
          // add row to DOM tree
          $('#buttonorder tbody').append(row);
          // make it draggable
          Drupal.tableDrag['buttonorder'].makeDraggable(row.get(0));
        }
      }

      /**
       * Removes draggable row for button (shortname)
       */
      function removeDraggableRow(id) {
        $('#'+id).remove();
      }

      // amount of separators
      var seps = 0;
      $('.separator').each( function() {
        seps++;
      });
      /**
       * Creates a draggable row ready for insertion
       * @return DOM element = filled row with attached events
       */
      function createDraggableRow(name,group,fullname){
        // if the name is a separator, make it unique
        var sepname = (name=='separator')? (name + '-' + ++seps) : '';
        // create the row(
        var row = $('<tr/>').addClass('draggable ' + ((sepname == '')? '' : 'separator ') + 'odd').attr('id','order-'+((sepname == '')? name : sepname));
        // append collumns
        $(row).append('<td>'+fullname+'</td>');
        $(row).append('<td><em>'+group+'</em></td>');
        $(row).append('<td class="tabledrag-hide" style="display: none;"></td>');
        $(row).append('<td><a href="#">Remove</a></td>');
        // Add "changed" to first collumn.
        $(row).find('td:first-child').append('<span class="warning tabledrag-changed">*</span>');
        // Add hidden weight component.
        $(row).find('td:nth-child(3)').append('<input type="hidden" name="buttonorder['+((sepname == '')? name : sepname)+'][weight]" id="edit-buttonorder-'+name+'-weight" value="1" class="buttons-weight">');

        // add remove link to last element, include events
        $(row).find('td:last a').addClass('removelink').click(function(e) {
          e.preventDefault();
          // check again if it's a separator
          if(sepname == '') {
            unCheckButton(name,group);
            removeDraggableRow('order-'+name);//tabledrag-hide
          }
          else {
            removeDraggableRow('order-'+sepname);
          }
          return false;
        });
        // return the row
        return row;
      }

      /**
       * Uncheck button in buttons fieldset
       */
      function unCheckButton(name,group){
        $('#edit-buttons-'+group+'-'+name).attr('checked',false);
      }
    }
  };

}(jQuery));
