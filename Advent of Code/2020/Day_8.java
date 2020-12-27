import java.util.*;
import java.io.*;

public class Day_8 {

    enum Op {
        nop,
        acc,
        jmp
    }

    static class Instr {
        Op op;
        int val;
    }

    static class PosAcc {
        int pos = 0;
        int acc = 0;
    }

    static List<Instr> getInput() {
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        List<Instr> res = new ArrayList<>();
        String line;

        while (!(line = in.nextLine()).isBlank()) {
            Instr newInstr = new Instr();
            String opStr = line.substring(0, 3);
            if (opStr.equals("acc")) {
                newInstr.op = Op.acc;
            }
            else if (opStr.equals("jmp")) {
                newInstr.op = Op.jmp;
            }
            else {
                newInstr.op = Op.nop;
            }
            newInstr.val = Integer.parseInt(line.substring(4));
            res.add(newInstr);
        }

        return res;
    }

    static List<Instr> in = getInput();

    static PosAcc calcAcc(List<Instr> in) {
        boolean[] visited = new boolean[in.size()];
        PosAcc posAcc = new PosAcc();

        while (posAcc.pos < in.size() && !visited[posAcc.pos]) {
            visited[posAcc.pos] = true;
            Instr instr = in.get(posAcc.pos);
            switch (instr.op) {
                case acc:
                    posAcc.acc += instr.val;
                    posAcc.pos++;
                    break;
                case jmp:
                    posAcc.pos += instr.val;
                    break;
                case nop:
                    posAcc.pos++;
                    break;
            }
        }

        return posAcc;
    }

    static class PartOne {
        public static void main(String[] args) {
            System.out.println(calcAcc(in).acc);
        }
    }

    static class PartTwo {
        public static void main(String[] args) {
            for (int i = 0; i < in.size(); i++) {
                Instr instr = in.get(i);

                if (instr.op == Op.nop || instr.op == Op.jmp) {
                    instr.op = (instr.op == Op.nop) ? Op.jmp : Op.nop;
                    PosAcc posAcc = calcAcc(in);
                    if (posAcc.pos == in.size()) {
                        System.out.println(posAcc.acc);
                        break;
                    }
                    else {
                        instr.op = (instr.op == Op.nop) ? Op.jmp : Op.nop;
                    }
                }
            }
        }
    }

}
