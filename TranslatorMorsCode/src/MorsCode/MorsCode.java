package MorsCode;

public class MorsCode {
    private String [] table;

    public MorsCode()
    {
        table = new String[37];
        table[0] = ".-";    //A
        table[1] = "-...";  //B
        table[2] = "-.-.";  //C
        table[3] = "-..";   //D
        table[4] = ".";     //E
        table[5] = "..-.";  //F
        table[6] = "--.";   //G
        table[7] = "....";  //H
        table[8] = "..";    //I
        table[9] = ".---";  //J
        table[10] = "-.-";  //K
        table[11] = ".-.."; //L
        table[12] = "--";   //M
        table[13] = "-.";   //N
        table[14] = "---";  //O
        table[15] = ".--."; //P
        table[16] = "--.-"; //Q
        table[17] = ".-.";  //R
        table[18] = "..."; //S
        table[19] = "-";    //T
        table[20] = "..-"; //U
        table[21] = "...-"; //V
        table[22] = ".--"; //W
        table[23] = "-..-"; //X
        table[24] = "-.--"; //Y
        table[25] = "--.."; //Z
        table[26] = "-----"; //0
        table[27] = ".----"; //1
        table[28] = "..---"; //2
        table[29] = "...--"; //3
        table[30] = "....-"; //4
        table[31] = "....."; //5
        table[32] = "-...."; //6
        table[33] = "--..."; //7
        table[34] = "---.."; //8
        table[35] = "----."; //9
        table[36] = "...---..."; //SOS
        table[36] = "...---..."; //
        table[36] = "...---..."; //SOS
        table[36] = "...---..."; //SOS
        table[36] = "...---..."; //SOS

    }


    public void translate(String str)
    {
        int len = str.length();
        String tmp = "";
        String solution = "";

        int i = 0, k = 0;
        while(true)
        {
            while(i < len && str.charAt(i) != ' ')
                i++;

            tmp = str.substring(k, i);
            for(int j = 0; j < 37; j++)
            {
                if(tmp.equals(table[j]))
                {
                    if(j == 36)
                        solution += "SOS";
                    else if(j >= 26)
                        solution += (char)('0' + j % 26);
                    else
                        solution += (char)('A' + j);

                    break;
                }
            }

            if(i + 2 < len && str.charAt(i + 1) == ' ' && str.charAt(i + 2) == ' ')
                solution += ' ';

            i++;
            k = i;

            if(i >= len)
                break;
        }

        System.out.println(solution);
    }


}
