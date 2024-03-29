// Cube object definition
let cube = {}

cube.init = () => {
    cube.data = {}
}

cube.move_list = {
    0:  {'face': 0, 'direction': 0},
    1:  {'face': 1, 'direction': 0},
    2:  {'face': 2, 'direction': 0},
    3:  {'face': 3, 'direction': 0},
    4:  {'face': 4, 'direction': 0},
    5:  {'face': 5, 'direction': 0},
    6:  {'face': 0, 'direction': 1},
    7:  {'face': 1, 'direction': 1},
    8:  {'face': 2, 'direction': 1},
    9:  {'face': 3, 'direction': 1},
    10: {'face': 4, 'direction': 1},
    11: {'face': 5, 'direction': 1}
}

cube.read = (data) => {
    let seq = [
        0,
        0,
        0,
        1,
        1,
        1,
        2,
        2,
        2,
        3,
        3,
        3,
        4,
        4,
        4,
        5,
        5,
        5
    ]

    if (!cube.data) 
        cube.init()

    let j = 0
    data
        .split('\n')
        .forEach(function (row, i) {
            let row_data = row.split('')

            if (!cube.data[seq[i]]) 
                cube.data[seq[i]] = []
            if (!cube.data[seq[i]][i % 3]) 
                cube.data[seq[i]][i % 3] = []

            cube.data[seq[i]][i % 3][0] = cube.convert(row_data[0])
            cube.data[seq[i]][i % 3][1] = cube.convert(row_data[1])
            cube.data[seq[i]][i % 3][2] = cube.convert(row_data[2])
        })
}

cube.convert = (val) => {
    let new_val = 0
    switch (val.charCodeAt(0)) {
        case 87:
            new_val = val.charCodeAt(0) - 87;
            break
        case 82:
            new_val = val.charCodeAt(0) - 81;
            break
        case 66:
            new_val = val.charCodeAt(0) - 64;
            break
        case 79:
            new_val = val.charCodeAt(0) - 76;
            break
        case 71:
            new_val = val.charCodeAt(0) - 67;
            break
        case 89:
            new_val = val.charCodeAt(0) - 84;
            break
        default:
            console.error('[ERR] Invalid color');
            break
    }

    return new_val
}

cube.update = () => {
    for (let i = 0; i < 6; i += 1) {
        for (let j = 0; j < 3; j += 1) {
            for (let k = 0; k < 3; k += 1) {
                let color_code = cube.data[i][j][k]
                let color_val
                switch (color_code) {
                    case 0:     color_val = 'white'; break
                    case 1:     color_val = 'red'; break
                    case 2:     color_val = 'blue'; break
                    case 3:     color_val = 'orange'; break
                    case 4:     color_val = 'green'; break
                    case 5:     color_val = 'yellow'; break
                    default:    color_val = 'white'; break
                }
                $('.face-' + i + ' .rubik-box.row-' + j + '.cell-' + k)
                    .hide()
                    .delay(0)
                    .css('background-color', color_val)
                    .text(cube.data[i][j][k])
                    .fadeIn()
            }
        }
    }
}

cube.rotate = (face, direction, data) => {
    if (data) return moveCube(data, face, direction)
    cube.data = moveCube(cube.data, face, direction)
    cube.update()
}

cube.set = (face, direction) => {
    cube._face = face
    cube._direction = direction
}

cube.exec = (data) => {
    return cube.rotate(cube._face, cube._direction, data)
}

cube.check = (data) => {
    let i, j, k

    if (typeof data == 'boolean' && data) {
        for (i = 0; i < 6; i++) {
            if (i == 0) {
                for (j = 0; j < 3; j++) {
                    for (k = 0; k < 3; k++) {
                        if (cube.data[i][j][k] != i) {
                            return false;
                        }
                    }
                }
            }
        }

        console.log("\n--CUBE SOLVED!--\n")
        return true
    } else return (data) => {
        cube.set(data.face, data.direction)

        let old_info = cube.data
        let new_info = cube.exec(cube.data)

        for (i = 0; i < 6; i++) {
            for (j = 0; j < 3; j++) {
                for (k = 0; k < 3; k++) {
                    if (new_info[0][1][1] != 0) return false // can never happen

                    // going away from white cross
                    if (Math.abs(j - k) == 1) {
                        if (new_info[0][j][k] != 0 && old_info[0][j][k] == 0) {
                            if (1 /*should check if edges of white cross is not valid*/) {
                                return false
                            }
                        }
                    }
                }
            }
        }

        return true // push to backtracking table
    }
}

cube.solve = () => {
    if (!cube.check()) return // should apply needed rotations

}
