import "Eks/EksBuild" as Eks;

Eks.SubModule {
  name: "GameAll"
  toRoot: "../"

  references: [
    "Eks/EksCore/EksCore.qbs",
    "Eks/Eks3D/Eks3D.qbs",
    "Eks/EksGui/EksGui.qbs",
    "Game.qbs",
  ]
}
