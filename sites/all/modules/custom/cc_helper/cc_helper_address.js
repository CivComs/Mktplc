(function ($) {
  Drupal.behaviors.ccHelper = {
      attach: function(context, settings) {
      field = $('#edit-field-organization-address-und-0');
      a1 = field.find('.thoroughfare');
      a2 = field.find('.premise');
      l = field.find('.locality');
      ar = field.find('.administrative-area');
      sar = field.find('.sub-administrative-area');
      c =  field.find('.country');
      tid = $('#edit-field-organization-type-und');
      a1.live('change', function() {updateAll(a1, a2, l, ar, sar, c, tid)});
      a2.live('change', function() {updateAll(a1, a2, l, ar, sar, c, tid)});
      l.live('change', function() {updateAll(a1, a2, l, ar, sar, c, tid)});
      ar.live('change', function() {updateAll(a1, a2, l, ar, sar, c, tid)});
      sar.live('change', function() {updateAll(a1, a2, l, ar, sar, c, tid)});
      c.live('change', function() {updateAll(a1, a2, l, ar, sar, c, tid)});
      tid.live('change', function() {updateAll(a1, a2, l, ar, sar, c, tid)});      
    }
  }

  function req(element, toggle) {
    if(toggle && element.parent().find('.form-required').length == 0) {
      element.parent().find('label').append('<span class="form-required" title="This field is required.">*</span>');
    }
    if(!toggle || toggle == '') {
      element.parent().find('.form-required').remove();
    }
  }

  function updateAll(a1, a2, l, ar, sar, c, tid) {
    qa1 = a1.val();
    qa2 = a2.val();
    ql = l.val();
    qar = ar.val();
    qsar = sar.val();
    qc = c.val();
    qtid = tid.val();
    req(a1, addressReq(qa1, qa2, ql, qar, qsar, qc, qtid));
    req(a2, addressReq(qa1, qa2, ql, qar, qsar, qc, qtid));
    req(l, cityReq(qa1, qa2, ql, qar, qsar, qc, qtid));
    req(ar, stateReq(qa1, qa2, ql, qar, qsar, qc, qtid));
    req(sar, countyReq(qa1, qa2, ql, qar, qsar, qc, qtid));
    req(c, countryReq(qa1, qa2, ql, qar, qsar, qc, qtid));
  }
}(jQuery));

function addressReq(a1, a2, l, ar, sar, c, tid) {
  return false;
}

function cityReq(a1, a2, l, ar, sar, c, tid) {
  return a1 || a2 || (tid == 127);
}

function countyReq(a1, a2, l, ar, sar, c, tid) {
  return tid == 129;
}

function stateReq(a1, a2, l, ar, sar, c, tid) {
  return sar || l || a1 || a2 || (tid == 130) || (tid == 129) || (tid == 127);
}

function countryReq(a1, a2, l, ar, sar, c, tid) {
  return ar || sar || l || a1 || a2 || (tid == 131) || (tid == 130) || (tid == 129) || (tid == 127);
}
