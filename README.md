# INF3_Schiffe
Project code by Maurice Mc Laughlin , Pascal Piel and Karl Kuckelsberg

| Server Client Protokoll  | Client sends | Server respons |
|---|---|---|
|  coordinates(shoot) |  KORDS + X + {x-coordinate} + Y + {y-coordinate} + #, {x-coordinate} and {y-coordinate} max. size of number is 10 | Water,  Ship_Hit, Ship_Destroyed, All_Ships_Destroyed, Game_Over|
|  new Game | RESTART  | RESTARTED|
|  end connection | BYEBYE  | BYEBYE |
|  error | "no valid command" | ERROR |
