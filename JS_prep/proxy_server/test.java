import java.util.*;

    class Machine {
        boolean isUp;
        ArrayList<String> commands;

        public Machine() {
            isUp = true;
            commands = new ArrayList<>();
        }
    }

    class Group {
        int last;
        ArrayList<Machine> machines;
        HashMap<String, Machine> map;

        Group() {
            last = -1;
            machines = new ArrayList<>();
        }
    }
    class Network {

        Map<String, Group> groups;

        Network() {
            groups = new HashMap<>();
        }

    }
    class TestClass {
        public static void main(String args[]) throws Exception {

            Network network = new Network();
            Scanner s = new Scanner(System.in);
            int n = Integer.parseInt(s.next());
            LinkedHashMap<String, Machine> machines = new LinkedHashMap<>();
            for (int i = 0; i < n; i++) {
                String name = s.next();
                machines.put(name, new Machine());
            }

            int g = s.nextInt();
            for (int i = 0; i < g; i++) {
                String proxyName = s.next();
                int m = s.nextInt();
                Group newGroup = new Group();
                for (int j = 0; j < m; j++) {
                    String machine = s.next();
                    Machine mc = machines.get(machine);
                    newGroup.machines.add(mc);
                }
                network.groups.put(proxyName, newGroup);
            }


            int q = s.nextInt();
            for (int i = 0; i < q; i++) {
                String query = s.next();
                executeQuery(network, machines, query);
            }


            machines.forEach((key, machine) -> {
                System.out.println(key);
                for (String command : machine.commands) {
                    System.out.println(command);
                }
            });
        }

        private static void executeQuery(Network network,LinkedHashMap<String, Machine> machines, String query) {
            String[] strings = query.split("/", 2);
            if(strings.length<1) {
                return;
            }
            String proxyName = strings[0];
            String remainingQuery = strings[1];
            Group  target = network.groups.get(proxyName);
            if (remainingQuery.contains("machine_down")) {
                String[] split = remainingQuery.split("=");
                String machineName = split[1];
                machines.get(machineName).isUp = false;
            } else if (remainingQuery.contains("machine_up")) {
                String[] split = remainingQuery.split("=");
                String machineName = split[1];
                machines.get(machineName).isUp = true;
            } else {

                int toProcess = (target.last != -1 ? target.last : 0)%target.machines.size();

                for(int i=toProcess; i<target.machines.size();i++) {
                    if(target.machines.get(i).isUp) {
                        target.machines.get(i).commands.add(query);
                        target.last = i+1;
                        return;
                    }
                }

                for(int i=0; i<target.last;i++) {
                    if(target.machines.get(i).isUp) {
                        target.machines.get(i).commands.add(query);
                        target.last = i+1;
                        return;
                    }
                }
            }

        }

    }