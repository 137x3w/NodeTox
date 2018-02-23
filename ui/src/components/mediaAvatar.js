import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from 'material-ui/styles';
import Avatar from 'material-ui/Avatar';
import classnames from 'classnames';

const styles = theme => ({
  avatarContainer: {
    position: 'relative',
    '&:after': {
      borderRadius: '50%',
      content: "''",
      width: '10px',
      height: '10px',
      position: 'absolute',
      bottom: '0',
      right: '0',
    },
  },
  offlineConnectionStatus: {
    '&:after': {
      backgroundColor: "transparent",
    }
  },
  noneConnectionStatus: {
    '&:after': {
      backgroundColor: "#76FF03",
    }
  },
  awayConnectionStatus: {
    '&:after': {
      backgroundColor: "#FFEA00",
    }
  },
  busyConnectionStatus: {
    '&:after': {
      backgroundColor: "#FF3D00",
    }
  },
  defaultStyle: {

  },
  contactListStyle: {
    width: '50px',
    height: '50px',
    margin: '10px',
    backgroundColor: theme.palette.secondary.main,
  }
});

class MediaAvatar extends React.Component {
  constructor(props) {
    super(props);
    this.classes = props.classes;
  }

  render() {
    return (
      <div className={
        classnames(this.classes.avatarContainer, 
                   this.classes[this.props.connectionStatus + 'ConnectionStatus'])
      }>
  			<Avatar alt="User avatar" src={ this.props.src } className={this.classes[this.props.styleType + 'Style']}>
          { this.props.src ? null : this.props.char }
        </Avatar>
      </div>
    );
  }
}

MediaAvatar.propTypes = {
  classes: PropTypes.object.isRequired,
  src: PropTypes.string,
  char: PropTypes.string,
  connectionStatus: PropTypes.string,
  styleType: PropTypes.string,
};

MediaAvatar.defaultProps = {
  src: "",
  char: "A",
  connectionStatus: "offline",
  styleType: "default",
}

export default withStyles(styles)(MediaAvatar);
