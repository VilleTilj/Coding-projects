#include "nukeactor.hh"

namespace StudentSide {

NukeActor::NukeActor(Interface::Location location):
    x_(location.giveX() + 900),
    y_(location.giveY() + 500),
    location_(location)
{

    setPos(mapToParent(x_, y_ ));

    assert(image.load(NUKE));
    image = image.scaled(NUKE_WIDTH, NUKE_HEIGHT);
    setPixmap(image);
}

NukeActor::~NukeActor()
{

}


}
