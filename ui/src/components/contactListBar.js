import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from 'material-ui/styles';
import Grid from 'material-ui/Grid';
import List from 'material-ui/List';
import ContactListItem from './contactListItem';

const styles = theme => ({
  contactsListBar: {
    overflow: 'auto',
    minHeight: '120px',
    height: 'calc(100vh - 135px)',
    backgroundColor: theme.palette.primary.main,
  },
});

class ContactListBar extends React.Component {
  constructor(props) {
    super(props);
    this.state = {};
    this.classes = props.classes;
  }
  
  handleProps(props) {
    var result = {
      contacts: props.contacts || [],
      contactListItemClickCallback: props.contactListItemClickCallback || (() => {}),
    }
    return result;
  }

  render() {
    this.safeProps = this.handleProps(this.props);
    return (    
      <Grid item align="center" className={ this.classes.contactsListBar }>
        <List disablePadding className={ this.classes.contactList }>
          {
            this.safeProps.contacts.map((item) => (
              <ContactListItem
                key={item.uid}
                uid={item.uid}
                nickname={item.nickname}
                statusMessage={item.statusMessage}
                avatarSrc={item.avatarSrc}
                connectionStatus={item.connectionStatus}
                unreadMessagesCount={item.unreadMessagesCount}
                listItemClickCallback={this.safeProps.contactListItemClickCallback}
              />
            ))
          }          
        </List>
      </Grid>
    );
  }
}

ContactListBar.propTypes = {
  classes: PropTypes.object.isRequired,
};

export default withStyles(styles)(ContactListBar);
