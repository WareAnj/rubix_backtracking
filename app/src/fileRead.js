$('#read-file input[type="submit"]').on('click', function () {
    $.ajax({
        url: 'res/input.txt',
        success: function (data) {
            alert(data)
        }
    })
})
