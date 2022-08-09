pkgname="openutils-map"
pkgver="1.6.6"
pkgrel="3"
pkgdesc="Memory Safe Map Library in C/C++ language."
arch=("x86_64" "i686")
conflicts=('openutils-map')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/map/master/map/map.hh" "https://raw.githubusercontent.com/Dark-CodeX/map/master/map/map.h" "https://raw.githubusercontent.com/Dark-CodeX/map/master/map/prototype_err.h")

sha512sums=("c0d8273267f38f211812bcfb464d481449b80e291253c6cea3fcf027ababc85c657a9f7af77cc04fc457f92eab8df2045faf689dac5b07a76b7f1dbed2811b2f" "7e7f53d704a7d7fa721c758ea52f5b4116bc1b014c1df8951b3e7ece7f58b9d364c1624e7865342b3f34da458964329bcc75f857e252ada85006beb25fe17ccb" "919505f7130e32468d3be6703dfd97028f120d13b099b80b8e821e4e9fe208a3eed4d95e43b6d77cd2dfce4e96e401f49616e12ecf7cae9c9ea93e210db99068")

package() {
	echo "Memory Safe Map Library in C++ language."
	mkdir -p "${pkgdir}/usr/include/openutils/map"
	cp "${srcdir}/map.hh" "${pkgdir}/usr/include/openutils/map/map.hh"
	cp "${srcdir}/map.h" "${pkgdir}/usr/include/openutils/map/map.h"
	cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/openutils/map/prototype_err.h"
	echo "Done!"
}
