# INF3_Schiffe
Project code by Maurice Mc Laughlin , Pascal Piel and Karl Kuckelsberg

| Server Client Protokoll  | Client sends | Server respons |
|---|---|---|
|  coordinates(shoot) |  KORDS + X + {x-coordinate} + Y + {y-coordinate} + #, {x-coordinate} and {y-coordinate} are numbers from 1 until  10, e.g. KORDSX10Y2# | Water,  ShipHit, ShipDestroyed, AllShipsDestroyed, GameOver|
|  new Game | RESTART  | RESTARTED|
|  end connection | BYEBYE  | BYEBYE |
|  error | "no valid command" | ERROR |
