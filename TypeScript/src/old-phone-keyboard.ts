const KEY_TO_CHAR = [" ", "&,^", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"];

const CHAR_TO_KEY_COUNT = (() => {
    const map = new Map<string, [string, number]>();
    for (let keyIndex = 0; keyIndex < KEY_TO_CHAR.length; keyIndex++) {
        const keyChar = String.fromCharCode("0".charCodeAt(0) + keyIndex);
        for (let charIndex = 0; charIndex < KEY_TO_CHAR[keyIndex].length; charIndex++) {
            const char = KEY_TO_CHAR[keyIndex][charIndex];
            map.set(char, [keyChar, charIndex + 1]);
        }
    }
    return map;
})();

function encodeToOldPhonePad(input: string) {
    let lastKey: string | null = null;
    let output = "";
    for (const char of input.toUpperCase()) {
        const keyCount = CHAR_TO_KEY_COUNT.get(char);
        if (keyCount == null) {
            throw new Error(`invalid character: '${char}'`);
        }
        const [key, count] = keyCount;
        if (key === lastKey) {
            output += " ";
        }
        output += key.repeat(count);
        lastKey = key;
    }
    return output;
}

function decodeFromOldPhonePad(input: string) {
    let output: string = "";
    for (let i = 0; i < input.length; i++) {
        const currentChar = input[i];
        const isDigit = /^[0-9]$/.test(currentChar);
        if (isDigit) {
            let charCount = 0;
            while (i < input.length && input[i] === currentChar) {
                charCount++;
                i++;
            }
            i--;
            const keyIndex = currentChar.charCodeAt(0) - "0".charCodeAt(0);
            const charIndex = (charCount - 1) % KEY_TO_CHAR[keyIndex].length;
            output += KEY_TO_CHAR[keyIndex][charIndex];
        } else if (currentChar !== " ") {
            throw new Error(`invalid character: '${currentChar}'`);
        }
    }
    return output;
}

console.log(encodeToOldPhonePad("MOAZ MAHMUD"));
console.log(decodeFromOldPhonePad("6 66629999062446883"));
