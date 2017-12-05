let dir = 0
$('.dir-0').on('click', () => {
    dir = 0
})

$('.dir-1').on('click', () => {
    dir = 1
})

let face_event = 0
$('.face-event-0').on('click', () => {
    face_event = 0
})

$('.face-event-1').on('click', () => {
    face_event = 1
})

$('.face-event-2').on('click', () => {
    face_event = 2
})

$('.face-event-3').on('click', () => {
    face_event = 3
})

$('.face-event-4').on('click', () => {
    face_event = 4
})

$('.face-event-5').on('click', () => {
    face_event = 5
})

$('.face-event').on('click', () => {
    cube.rotate(face_event, dir)
})
