// TODO: Feels like I'm going at this the wrong way
// There must be a better way to do this
import { readFile } from "fs/promises";

async function getLines(): Promise<string[]> {
    const buf = await readFile("./day_three.test");
    return buf.toString().split("\n");
}

function getFullNumberAroundItem(row: string, x: number): number {
    // Check forwards at first
    let number = "";
    console.log(`Checking ${row} at ${x}`);

    for (x; x < row.length; x++) {
        if (row[x] === ".") break;
        while (x < row.length && !isNaN(parseInt(row[x]))) {
            number += row[x];
            x++;
        }
    }

    return parseInt(number);

}

function getAdj(y: number, x: number): number[][] {
    return [
        [y - 1, x - 1], [y - 1, x], [y - 1, x + 1], [y, x - 1],
        [y, x + 1], [y + 1, x - 1], [y + 1, x], [y + 1, x + 1],
    ];
}

async function main() {
    const lines = await getLines();
    let gearPos: number[][] = [];

    for (let y = 0; y < lines.length; y++) {
        const line = lines[y];
        for (let x = 0; x < line.length; x++) {
            if (lines[y][x] === "*") {
                gearPos.push([y, x])
            }
        }
    }

    gearPos.map(gear => {
        const y = gear[0];
        const x = gear[1];
        const adj = getAdj(y, x);

        adj.map((adj => {
            const adj_y = adj[0];
            const adj_x = adj[1];
            const char = lines[adj_y][adj_x];

            if (char === ".") return;

            console.log(`Checking the cords (${adj_y}, ${adj_x})`);
            const number = getFullNumberAroundItem(lines[adj_y], adj_x);
            console.log(number);
        }))
    })
}

main();
